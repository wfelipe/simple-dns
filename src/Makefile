CC = gcc
CFLAGS = -g -O0 -Wall
headers = server.h dns_protocol.h
objects = server.o simple-dns.o test.o dns_protocol.o client.o

.c.o:
	$(CC) $(CFLAGS) -c $<

all: simple-dns client

simple-dns: server.o simple-dns.o dns_protocol.o
	$(CC) $(CFLAGS) -o simple-dns server.o simple-dns.o dns_protocol.o

client: dns_protocol.o client.o
	$(CC) $(CFLAGS) -o client client.o dns_protocol.o

test: server.o test.o dns_protocol.o
	$(CC) $(CFLAGS) -o test server.o test.o dns_protocol.o

$(objects): $(headers)

clean:
	rm -f $(objects) simple-dns test client
