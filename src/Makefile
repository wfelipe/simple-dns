CC = gcc
CFLAGS = -g -O0
headers = dns.h
objects = dns.o main.o

.c.o:
	$(CC) $(CFLAGS) -c $<

all: simple-dns

simple-dns: $(objects)
	$(CC) $(CFLAGS) -o simple-dns $(objects)

$(objects): $(headers)

clean:
	rm -f $(objects)
