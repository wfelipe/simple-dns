/*
 * Implementation of RFC 1035
 * DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION
 * http://www.ietf.org/rfc/rfc1034.txt
 * http://www.ietf.org/rfc/rfc1035.txt
 */

#include <arpa/inet.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

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

int dns_packet_parse (struct dns_packet *pkt, void *data, u_int16_t size)
{
	dns_header_parse (&pkt->header, data);

	pkt->data = malloc (size - 12);
	memcpy (pkt->data, data + 12, size - 12);

	return 1;
}

int dns_header_parse (struct dns_header *header, void *data)
{
	memcpy (header, data, 12);

	header->id = ntohs (header->id);
	header->attr = ntohs (header->attr);
	header->qdcount = ntohs (header->qdcount);
	header->ancount = ntohs (header->ancount);
	header->nscount = ntohs (header->nscount);
	header->arcount = ntohs (header->arcount);

	return 1;
}
