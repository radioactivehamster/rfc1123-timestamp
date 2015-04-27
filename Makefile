mandocpath = mandoc

.PHONEY: mandoc
.SUFFIXES: .m4.mdoc .mdoc

all: mandoc

mandoc:
	$(MAKE) -C $(mandocpath)

.m4.mdoc.mdoc:
	$(MAKE) -C $(mandocpath) $@
