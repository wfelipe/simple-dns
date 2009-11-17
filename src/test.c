#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <assert.h>
#include "server.h"

int main (int argc, char **argv)
{
	int ret;

	open_sockets ();
	printf ("open_socket: %d\n", ret);
	sleep (10);

	return 0;
}
