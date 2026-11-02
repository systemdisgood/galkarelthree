CC = g++
CFLAGS = -Wall -pedantic -std=c++11

BINARIES = galkarelthree looper

SRCS = $(addsuffix .c, $(BINARIES))
OBJS = $(addsuffix .o, $(BINARIES))

.PHONY: all clean

all: $(BINARIES)


%.out: %.o
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BINARIES)

