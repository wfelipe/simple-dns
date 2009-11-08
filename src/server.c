#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

void dns_init ()
{
	open_socket ();
}

int open_socket ()
{
	struct sockaddr_in si_me, si_other;
	int s;
	char buf[255];

	if ((s = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == - 1)
		return -1;

	memset ((char *) &si_me, 0, sizeof (si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons (53);
	si_me.sin_addr.s_addr = htonl (INADDR_ANY);
	if (bind (s, &si_me, sizeof (si_me)) == - 1)
		return -1;

	return 0;
}
