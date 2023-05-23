CC      = gcc
CFLAGS  = -g
RM      = rm -f

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

default: all

all: complex_chain_generator

complex_chain_generator: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lssl -lcrypto

clean:
	$(RM) complex_chain_generator $(OBJS)
