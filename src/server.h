#ifndef __SERVER_H__
#define __SERVER_H__

struct dns_server
{
	struct dns_config config;
	int listen_sock;
};

struct dns_config
{
  char *host;
  int port;
};

extern struct dns_server dns_server;

void dns_init (void);
int open_socket (void);

#endif
