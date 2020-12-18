# Copyright (C) 2020 Robert Coffey
# Released under the GPLv2 license

CC=gcc

SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:%.c=%.o)
PROGS=fogoff

all: $(PROGS)
	$(CC) -o fogoff $(OBJS)

$(PROGS): $(OBJS)

$(OBJS): $(SRCS)

.PHONY: clean
clean:
	rm src/*.o

.PHONY: uninstall
uninstall:
	rm src/*.o fogoff
