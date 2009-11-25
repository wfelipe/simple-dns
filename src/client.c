#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "dns_protocol.h"

int main (int argc, char **argv)
{
	struct dns_packet *packet;
	struct sockaddr_in sin;
	int sin_len = sizeof (sin);
	int sock;
	char buf[256];
	int buf_len = 0;

	sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	memset ((char *) &sin, 0, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons (53);
//	inet_aton ("127.0.0.1", &sin.sin_addr);
	inet_aton ("201.6.0.103", &sin.sin_addr);

	packet = calloc (1, sizeof (struct dns_packet));
	packet->header.id = 2048;

	memcpy (buf, &packet->header, 12);
	buf_len = 12;
	memcpy (buf + buf_len, "www.uol.com.br", sizeof ("www.uol.com.br"));
	buf_len += sizeof ("www.uol.com.br");

	sendto (sock, buf, buf_len, 0, (struct sockaddr *) &sin, sin_len);
	recv (sock, buf, 255, 0);

	printf ("%s\n", buf);

	return 0;
}
