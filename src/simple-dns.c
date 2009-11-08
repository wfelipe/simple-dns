#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <syslog.h>

#include "server.h"

int main (int argc, char **argv)
{
	int o;
	int p_arg = 53;
	char *h_arg = NULL;
	char *f_arg = NULL;
	int F_flag = 0;

	setbuf (stdout, NULL);
	setbuf (stderr, NULL);

	while ((o = getopt (argc, argv, "h:p:f:F")) != -1)
		switch (o)
		{
			case 'h':
			  dns_server.config.host = optarg;
				h_arg = optarg;
				break;
			case 'p':
				assert (p_arg = atoi (optarg));
				break;
			case 'f':
				f_arg = optarg;
				break;
			case 'F':
				F_flag = 1;
			default:
				abort ();
		}

	openlog ("simple-dns", LOG_PID, LOG_LOCAL0);
	syslog (LOG_INFO, "host: %s port: %d", h_arg, p_arg);

	open_socket ();

	return 0;
}
