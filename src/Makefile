CC = gcc
CFLAGS = -g -O0 -Wall
headers = server.h dns_protocol.h
objects = server.o simple-dns.o test.o dns_protocol.o

.c.o:
	$(CC) $(CFLAGS) -c $<

all: simple-dns test

simple-dns: server.o simple-dns.o dns_protocol.o
	$(CC) $(CFLAGS) -o simple-dns server.o simple-dns.o dns_protocol.o

test: server.o test.o dns_protocol.o
	$(CC) $(CFLAGS) -o test server.o test.o dns_protocol.o

$(objects): $(headers)

clean:
	rm -f $(objects) simple-dns test
