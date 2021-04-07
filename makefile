# Copyright (C) 2020-2021 Robert Coffey
# Released under the MIT license

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

PROG := fogoff

HEDS := $(wildcard src/*.h)
HEDS := $(HEDS) $(wildcard src/caesar/*.h)

SRCS := $(wildcard src/*.c)
SRCS := $(SRCS) $(wildcard src/caesar/*.c)

OBJS := $(SRCS:%.c=%.o)

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
