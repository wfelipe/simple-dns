CC = gcc
CFLAGS = -g -O0
headers = server.h
objects = server.o simple-dns.o test.o

.c.o:
	$(CC) $(CFLAGS) -c $<

all: simple-dns test

simple-dns: server.o simple-dns.o
	$(CC) $(CFLAGS) -o simple-dns server.o simple-dns.o

test: server.o test.o
	$(CC) $(CFLAGS) -o test server.o test.o

$(objects): $(headers)

clean:
	rm -f $(objects) simple-dns test
