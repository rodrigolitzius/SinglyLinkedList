STATIC=libsll.a
SHARED=libsll.so
TEST=testing

SRC=./src
COMP=./comp
BIN=./bin

CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -pedantic -pedantic-errors

CFLAGS_RELEASE=-O2
CFLAGS_DEBUG=-g -O0

FILES=./src/sll.c
OBJECTS=$(patsubst $(SRC)/%,$(COMP)/%,$(patsubst %.c,%.o,$(FILES)))
DEPENDS=$(patsubst $(SRC)/%,$(COMP)/%,$(patsubst %.c,%.d,$(FILES)))

DEBUG ?= 0

.PHONY: all clean

all: static shared

test: static
	$(CC) $(SRC)/test.c $(BIN)/$(STATIC) -o $(BIN)/$(TEST)

static: $(OBJECTS)
	ar rcs $(BIN)/$(STATIC) $<

shared: $(OBJECTS)
	$(CC) $^ -fPIC -shared -o $(BIN)/$(SHARED)

-include $(DEPENDS)
$(COMP)/%.o: $(SRC)/%.c Makefile
ifeq ($(DEBUG),0)
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS) $(CFLAGS_RELEASE)
endif

ifeq ($(DEBUG),1)
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS) $(CFLAGS_DEBUG)
endif

clean:
	@rm $(COMP)/*
	@rm $(BIN)/*