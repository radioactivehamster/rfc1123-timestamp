CFLAGS      = -std=c11 -O2 -pedantic -Wall -Wextra
TESTSBINDIR = bin

.PHONEY: test

all: test

clean:
	@rm -rf $(TESTSBINDIR)

test:
	@if test ! -d $(TESTSBINDIR); then mkdir $(TESTSBINDIR); fi
	@$(CC) $(CFLAGS) -o "$(TESTSBINDIR)/rfc1123_gmt_timestamp" \
	    "rfc1123_gmt_timestamp.c" -lcheck
	@./"$(TESTSBINDIR)/rfc1123_gmt_timestamp"
