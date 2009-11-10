#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <syslog.h>

#include "server.h"

struct dns_server dns_server;

int main (int argc, char **argv)
{
	int o;

	setbuf (stdout, NULL);
	setbuf (stderr, NULL);

	dns_init ();

	while ((o = getopt (argc, argv, "h:p:f:F")) != -1)
		switch (o)
		{
			case 'h':
				dns_server.config.host = optarg;
				break;
			case 'p':
				assert (dns_server.config.port = atoi (optarg));
				break;
			case 'f':
				dns_server.config.config_file = optarg;
				break;
			case 'F':
				dns_server.config.fg = 1;
			default:
				abort ();
		}

	syslog (LOG_INFO, "host: %s port: %d",
		dns_server.config.host, dns_server.config.port);

	dns_start ();
	dns_loop ();

	return 0;
}
