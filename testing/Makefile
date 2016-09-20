TEST_PROGS := app-diff-test

OBJS =				\
	test.o			\
	test-api.o

CFLAGS += -Wall -I../include/

all: $(TEST_PROGS)

include lib.mk

clean:
	$(RM) $(TEST_PROGS)

%.o: %.c test.h ../include/api.h
	$(CC) $(CFLAGS) -c $< -o $@

app-diff-test: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
