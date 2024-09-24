CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

ykr_cc: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): ykr_cc.h

test: ykr_cc
	./test.sh

clean:
	rm -f ykr_cc *.o *~ tmp*

.PHONY: test clean