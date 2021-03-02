CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -I./inc/

PROG=fogoff
HEDS=$(wildcard inc/*.h)
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:%.c=%.o)

all: $(PROG)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)
$(PROG): $(OBJS)
$(OBJS): $(HEDS)
$(OBJS): $(SRCS)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: remove
remove:
	rm -f $(OBJS) $(PROG)
