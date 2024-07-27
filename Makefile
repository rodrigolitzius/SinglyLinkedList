OUTPUT_FILE=main
SRC=./src
COMP=./comp

FILES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%,$(COMP)/%,$(patsubst %.c,%.o,$(FILES)))
DEPENDS=$(patsubst $(SRC)/%,$(COMP)/%,$(patsubst %.c,%.d,$(FILES)))

CC=gcc
CFLAGS=-g -O0 -std=c17 -Wall -Wextra -pedantic -pedantic-errors
CFLAGS_LINKTIME=-fsanitize=undefined,address,leak

.PHONY: all clean

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUT_FILE) $(CFLAGS_LINKTIME) $(CFLAGS)

-include $(DEPENDS)
$(COMP)/%.o: $(SRC)/%.c Makefile
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS)

clean:
	@rm $(COMP)/*