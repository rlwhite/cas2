
SRCS= \
 20160508.md

TGTS := $(SRCS:.md=.html)

blog: $(TGTS)
	echo "$@"
	touch blog

%.html: %.md
	markdown $<  > $@

clean:
	rm -f $(TGTS) .blog
