/*
 * Implementation of RFC 1035
 * DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION
 * http://www.ietf.org/rfc/rfc1034.txt
 * http://www.ietf.org/rfc/rfc1035.txt
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "dns_protocol.h"

int dns_parse_request (struct dns_packet *req, char *packet, int size)
{
	//printf ("%s\n", packet);
	req = (struct dns_packet *) packet;

	return 0;
}

void dns_print_packet (struct dns_packet *packet)
{
	printf ("ID: %d\n", packet->id);
	printf ("attr: %d\n", packet->attr);
	printf ("qdcount: %d\n", packet->qdcount);
	printf ("ancount: %d\n", packet->ancount);
	printf ("nscount: %d\n", packet->nscount);
	printf ("arcount: %d\n", packet->arcount);
}
