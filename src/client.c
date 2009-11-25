#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "dns_protocol.h"

int main (int argc, char **argv)
{
	struct dns_packet *packet;

	packet = calloc (1, sizeof (struct dns_packet));
	packet>header.id = 2048;
	

	return 0;
}
