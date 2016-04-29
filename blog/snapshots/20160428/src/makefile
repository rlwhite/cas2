
.PHONY:all
all:
	$(MAKE) -C casTest $@

.PHONY: build
build: clean all

	$(MAKE) -C casTest $@

.PHONY: clean
clean: 
	$(MAKE) -C casTest $@

.PHONY: distro
distro: distclean all
	$(MAKE) -C casTest $@

.PHONY: distclean
distclean: clean
	$(MAKE) -C casTest $@

%:
	$(MAKE) -C casTest $@
