CFLAGS = -Wall -Werror -std=gnu99 -g -I.
TARGET = test

# `make V=1` is equal to `make VERBOSE=1`
ifeq ("$(origin V)", "command line")
    VERBOSE = $(V)
endif

ifeq ("$(VERBOSE)","1")
    Q :=
    VECHO = @true
else
    Q := @
    VECHO = @printf
endif

OBJS = mallok.o test.o
deps := $(OBJS:%.o=.%.o.d)

%.o: %.c
	$(VECHO) "  CC\t$@\n"
	$(Q)$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<

$(TARGET): $(OBJS)
	$(VECHO) "  LD\t$@\n"
	$(Q)$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJS) $(deps)
