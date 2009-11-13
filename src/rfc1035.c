/*
 * Implementation of RFC 1035
 * DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION
 * http://www.ietf.org/rfc/rfc1034.txt
 * http://www.ietf.org/rfc/rfc1035.txt
 */

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

struct dns_packet
{
		u16 id; /* a 16 bit identifier assigned by the client */
		u16 attr; /* a 16 bit, identifying:
					 qr (1)
					 opcode (4)
					 aa (1)
					 tc (1)
					 rd (1)
					 ra (1)
					 z (3)
					 rcode (4) */
		u16 qdcount;
		u16 ancount;
		u16 nscount;
		u16 arcount;
};
