mandocdir = mandoc
testdir   = test

CFLAGS = -std=c11 -O2 -pedantic -Wall -Wextra

.PHONEY: mandoc test

all: mandoc

clean:
	@$(MAKE) -C $(mandocdir) clean
	@$(MAKE) -C $(testdir) clean

mandoc:
	@$(MAKE) -C $(mandocdir)

test:
	@$(MAKE) -C $(testdir)
