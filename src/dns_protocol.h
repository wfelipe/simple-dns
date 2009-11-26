#ifndef __DNS_PROTOCOL_H__
#define __DNS_PROTOCOL_H__

#include <sys/types.h>

/* QR
 * a one bit field that specifies whether this message is a query
 * or a response
 */
#define QR_QUERY 0
#define QR_RESPONSE 1

/* OPCODE
 * a four bit field that specifies kind of query in this message
 */
#define OPCODE_QUERY 0 /* a standard query */
#define OPCODE_IQUERY 1 /* an inverse query */
#define OPCODE_STATUS 2 /* a server status request */
/* 3-15 reserved for future use */

/* AA
 * one bit, valid in responses, and specifies that the responding
 * name server is an authority for the domain name in question
 * section
 */
#define AA_NONAUTHORITY 0
#define AA_AUTHORITY 1

struct dns_header
{
	u_int16_t id; /* a 16 bit identifier assigned by the client */
	u_int16_t attr; /* a 16 bit, identifying:
				qr (1)
				opcode (4)
				aa (1)
				tc (1)
				rd (1)
				ra (1)
				z (3)
				rcode (4) */
	u_int16_t qdcount;
	u_int16_t ancount;
	u_int16_t nscount;
	u_int16_t arcount;
};


struct dns_packet
{
	struct dns_header header;
//	struct dns_question question;
	char *data;
	u_int16_t data_size;
};

struct dns_response_packet
{
	char *name;
	u_int16_t type;
	u_int16_t class;
	u_int32_t ttl;
	u_int16_t rdlength;
	char *rdata;
};

struct dns_question
{
	char *qname;
	u_int16_t qtype;
	u_int16_t qclass;
};

void dns_print_header (struct dns_header *header);
void dns_print_packet (struct dns_packet *packet);

int dns_request_parse (struct dns_packet *pkt, void *data, u_int16_t size);
int dns_header_parse (struct dns_header *header, void *data);
int dns_question_parse (struct dns_packet *pkt);

#endif
