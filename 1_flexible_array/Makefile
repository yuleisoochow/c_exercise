
CC = gcc

CFLAGS = -Wall -O2 -s

LDFLAGS = -L./

BIN = $(shell pwd | sed "s/.*\///" | cut -c3-) 

SOURCE = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SOURCE))
#OBJS = $(shell ls *\.c | sed "s/\.c$$/.o/")

all: $(BIN)
	cp $(BIN) $(TARGET_DIR)/

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LDFLAGS)


%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean:
	rm -f $(OBJS) $(BIN) *.o *.d *.ko

run:
	./$(BIN)

