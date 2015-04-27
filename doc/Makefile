TARGETS = mdoc html man txt
VERSION = 0.1.0

date       ?= $(shell date -u "+%B %d, %Y")
txtoutput  ?= utf8
m4includes := $(wildcard _src/_include/*.m4)
name        = rfc1123_gmt_timestamp
manfile     = $(name).3

.SUFFIXES: .%.mdoc.m4

all: $(TARGETS)

mdoc:
	@m4 -D __NAME__="$(name)" -D __DATE__="$(date)" -D __VERSION__="$(VERSION)" \
	   -I "_src/$(manfile)" $(m4includes) \
	   "_src/$(manfile).mdoc.m4" > $(manfile).mdoc
	@if (which -s mandoc); then \
		mandoc -Tlint $(manfile).mdoc; \
	fi;
	@mkdir -p $@
	@mv $(manfile).mdoc $@/$(manfile)

html: mdoc
	@mkdir -p $@
	@mandoc -Thtml mdoc/$(manfile) > $@/$(manfile).html

man: mdoc
	@mkdir -p $@
	@mandoc -Tman mdoc/$(manfile) > $@/$(manfile)

txt: mdoc
	@mkdir -p $@
	@mandoc -T$(txtoutput) mdoc/$(manfile) | col -b > $@/$(manfile).txt

clean:
	@rm -rf $(TARGETS)
