mandocdir = mandoc
testdir   = test

.PHONEY: mandoc test

all: mandoc

clean:
	@$(MAKE) -C $(mandocdir) clean
	@$(MAKE) -C $(testdir) clean

distclean:
	@$(MAKE) -C $(testdir) clean

mandoc:
	@$(MAKE) -C $(mandocdir)

test:
	@$(MAKE) -C $(testdir)
