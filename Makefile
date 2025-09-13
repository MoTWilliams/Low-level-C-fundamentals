CC := gcc

.DEFAULT_GOAL := all

CFLAGS += -std=c17 -pedantic -Wall -Wextra -g
SRC := $(wildcard *.c)

OBJ := $(patsubst %.c, obj/%.o, $(SRC))

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

BINS := $(patsubst obj/%.o, bin/%, $(OBJ))

bin/%: obj/%.o
	@mkdir -p $(dir $@)
	$(CC) -o $@ $<

.SECONDARY:

.PHONY: pa1
pa1: $(BINS)

.PHONY: all
all: 
	$(MAKE) $(BINS)

.PHONY: 1 2 3 4
1: bin/1_sumExp
	./bin/1_sumExp
2: bin/2_sumFact
	./bin/2_sumFact
3: bin/3_cString
	./bin/3_cString
4: bin/4_sine
	./bin/4_sine

.PHONY: run
run:
	$(MAKE) 1 2 3 4

.PHONY: clean
clean:
	$(RM) -r obj bin