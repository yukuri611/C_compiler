CFLAGS=-std=c11 -g -static

ykr_cc: ykr_cc.c

test: ykr_cc
		./test.sh

clean:
		rm -f ykr_cc *.o *~ tmp*

.PHONY: test clean