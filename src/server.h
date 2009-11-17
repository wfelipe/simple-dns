#ifndef __SERVER_H__
#define __SERVER_H__

#define PACKET_SIZE 512

struct dns_config
{
	char *config_file;
	int fg;

	char *host;
	int port;
};

struct dns_server
{
	struct dns_config config;
	int listenfd;
};

extern struct dns_server dns_server;

void dns_init (void);
void open_sockets (void);
void dns_start (void);
void dns_loop (void);

#endif
