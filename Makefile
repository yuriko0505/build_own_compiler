CFLAGS=-std=c11 -g -static

ycc: main.o
	$(CC) -o $@ $? $(LDFLAGS)

test: ycc
	./test.sh

clean:
	rm -f ycc *.o *~ tmp*

.PHONY: test clean