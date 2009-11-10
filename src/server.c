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

	dns_server.listen_sock = 0;
}

/*
 * open listen sockets and set flags
 */
void open_sockets (void)
{
	struct sockaddr_in si_me, si_other;
	int sd;
	char buf[255];

	printf ("Opening sockets.\n");

	assert ((sd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) > 0);

	memset ((char *) &si_me, 0, sizeof (si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons (dns_server.config.port);
	si_me.sin_addr.s_addr = htonl (INADDR_ANY);
	assert (bind (sd, &si_me, sizeof (si_me)) == 0);
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
	printf ("Accepting connections...\n");
}
