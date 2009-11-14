/*
 * Implementation of RFC 1035
 * DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION
 * http://www.ietf.org/rfc/rfc1034.txt
 * http://www.ietf.org/rfc/rfc1035.txt
 */

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "dns_protocol.h"

struct dns_packet *parse_request (void *packet, int size)
{
	struct dns_packet *req;

	assert (req = malloc (sizeof (struct dns_packet *)));

	return req;
}
