
CC = gcc

CFLAGS = -Wall -g

TARGETS = nfl temp

all: $(TARGETS)

nfl: nfl.c
	$(CC) $(CFLAGS) nfl.c -o nfl

temp: temp.c
	$(CC) $(CFLAGS) temp.c -o temp

clean:
	rm -f $(TARGETS)