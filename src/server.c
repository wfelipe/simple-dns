#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <syslog.h>

#include "dns_protocol.h"
#include "server.h"

struct dns_server dns_server;

/*
 * initialize dns_server
 */
void dns_init (void)
{
	printf ("Initializing DNS server.\n");

	dns_server.config.config_file = NULL;
	dns_server.config.fg = 0;

	dns_server.config.port = 53;
	dns_server.config.host = INADDR_ANY;

	dns_server.listenfd = 0;
}

/*
 * open listen sockets and set flags
 */
void open_sockets (void)
{
	struct sockaddr_in si_me;
	int sd;
	char buf[255];

	printf ("Opening sockets.\n");

	assert ((sd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) > 0);

	memset ((char *) &si_me, 0, sizeof (si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons (dns_server.config.port);
	si_me.sin_addr.s_addr = inet_addr (dns_server.config.host);
	assert (bind (sd, (struct sockaddr *) &si_me, sizeof (si_me)) == 0);

	dns_server.listenfd = sd; 
}

/*
 * after parsing configuration, start the dns_server
 */
void dns_start (void)
{
	printf ("Starting DNS server.\n");

	openlog ("simple-dns", LOG_PID, LOG_LOCAL0);

	open_sockets ();
}

/*
 * loop accepting new requests
 */
void dns_loop (void)
{
	int client;
	socklen_t addrlen;
	struct sockaddr_in addr;
	char buffer[1024];
	struct dns_packet *req;

	printf ("Accepting connections...\n");
	for (;;)
	{
		client = recvfrom (dns_server.listenfd, buffer, 1024, 0, (struct sockaddr *) &addr, &addrlen);
		req = parse_request (buffer, sizeof (buffer));
	}
}
