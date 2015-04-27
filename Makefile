docdir  = doc
testdir = test

.PHONEY: mandoc test

all: distclean doc

clean:
	@$(MAKE) -C $(docdir) clean
	@$(MAKE) -C $(testdir) clean

distclean:
	@$(MAKE) -C $(testdir) clean

doc:
	@$(MAKE) -C $(docdir)

test:
	@$(MAKE) -C $(testdir)
