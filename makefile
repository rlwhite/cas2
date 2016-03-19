# The "Clean And Simple" (CAS) software framework, tools, and documentation
# are distributed under the terms of the MIT license a copy of which is
# included with this package (see the file "LICENSE" in the CAS poject tree's
# root directory).  CAS may be used for any purpose, including commercial
# purposes, at absolutely no cost. No paperwork, no royalties, no GNU-like
# "copyleft" restrictions, either.  Just download it and use it.
# 
# Copyright (c) 2016 Randall Lee White

.PHONY:all
all:
	$(MAKE) -C src $@

.PHONY: build
build: clean all

	$(MAKE) -C src $@

.PHONY: clean
clean: 
	$(MAKE) -C src $@

.PHONY: distro
distro: distclean all
	$(MAKE) -C src $@

.PHONY: distclean
distclean: clean
	rm -f `find . -name "#*"` `find . -name "*~"`

%:
	$(MAKE) -C src $@
