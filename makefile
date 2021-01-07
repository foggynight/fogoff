# Copyright (C) 2020-2021 Robert Coffey
# Released under the GPLv2 license

CC=gcc
CFLAGS=-I./inc/

HEDS=$(wildcard inc/*.h)
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:%.c=%.o)
PROGS=fogoff

all: $(PROGS)
	$(CC) $(CFLAGS) -o fogoff $(OBJS)
$(PROGS): $(OBJS)
$(OBJS): $(SRCS)
$(SRCS): $(HEDS)

.PHONY: clean
clean:
	rm -f src/*.o

.PHONY: uninstall
uninstall:
	rm -f src/*.o fogoff
