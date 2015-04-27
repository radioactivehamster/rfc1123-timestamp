docdir  = doc
testdir = test

.PHONEY: doc

all: distclean doc

check:
	@$(MAKE) -C $(testdir)

clean:
	@$(MAKE) -C $(docdir) clean
	@$(MAKE) -C $(testdir) clean

distclean:
	@$(MAKE) -C $(testdir) clean

doc:
	@$(MAKE) -C $(docdir)

