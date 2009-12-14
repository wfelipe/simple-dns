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
	printf ("qr: %d\n", header->qr);
	printf ("opcode: %d\n", header->opcode);
	printf ("aa: %d\n", header->aa);
	printf ("tc: %d\n", header->tc);
	printf ("rd: %d\n", header->rd);
	printf ("ra: %d\n", header->ra);
	printf ("z: %d\n", header->z);
	printf ("rcode: %d\n", header->rcode);

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

int dns_request_parse (struct dns_packet *pkt, void *data, u_int16_t size)
{
	int i;

	dns_header_parse (&pkt->header, data);

	pkt->data = malloc (size - 12);
	memcpy (pkt->data, data + 12, size - 12);
	pkt->data_size = size - 12;

	i = 0;
	while (i < pkt->header.qdcount)
	{
		dns_question_parse (pkt);
		i++;
	}

	return 1;
}

int dns_header_parse (struct dns_header *header, void *data)
{
	memcpy (header, data, 12);

	header->id = ntohs (header->id);
	header->qdcount = ntohs (header->qdcount);
	header->ancount = ntohs (header->ancount);
	header->nscount = ntohs (header->nscount);
	header->arcount = ntohs (header->arcount);

	return 1;
}

int dns_question_parse (struct dns_packet *pkt)
{
	u_int16_t i, length, j;
	char *question = pkt->data;

	i = 0;
	length = question[i++];

	do
	{
		printf ("SIZE: %d\n", length);
		for (j = 0; j < length; j++)
		{
			printf ("%c", question[i + j]);
		}
		printf ("\n");
		i += length;
		length = question[i++];
	} while (length != 0 && i < pkt->data_size);

	return 1;
}
