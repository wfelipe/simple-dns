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

void dns_print_header (struct dns_header *header)
{
	printf ("ID: %d\n", header->id);
	printf ("attr: %d\n", header->attr);

	printf ("\tqr: %d\n", header->attr & 0x8000);
	printf ("\topcode: %d\n", header->attr & 0x7800);
	printf ("\taa: %d\n", header->attr & 0x0400);
	printf ("\ttc: %d\n", header->attr & 0x0200);
	printf ("\trd: %d\n", header->attr & 0x0100);
	printf ("\tra: %d\n", header->attr & 0x0080);
	printf ("\tz: %d\n", header->attr & 0x0070);
	printf ("\trcode: %d\n", header->attr & 0x000F);

	printf ("qdcount: %d\n", header->qdcount);
	printf ("ancount: %d\n", header->ancount);
	printf ("nscount: %d\n", header->nscount);
	printf ("arcount: %d\n", header->arcount);
}

void dns_print_packet (struct dns_packet *packet)
{
	dns_print_header (&packet->header);
	printf ("data_size: %d\n", packet->data_size);
	printf ("data: %s\n", packet->data);
}
