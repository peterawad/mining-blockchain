CC      = gcc
CFLAGS  = -g
RM      = rm -f

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

default: all

all: mining_chain

mining_chain: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lssl -lcrypto

clean:
	$(RM) mining_chain $(OBJS)
