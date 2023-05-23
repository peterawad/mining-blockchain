CC      = gcc
CFLAGS  = -g
RM      = rm -f

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

default: all

all: chain_generator

chain_generator: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lssl -lcrypto

clean:
	$(RM) chain_generator $(OBJS)
