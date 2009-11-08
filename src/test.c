#include <stdio.h>
#include "server.h"

int main (int argc, char **argv)
{
	int ret;

	ret = open_socket ();
	printf ("open_socket: %d\n", ret);
	sleep (10);
}
