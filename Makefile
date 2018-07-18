
SHELL = /bin/bash

SUBDIR = $(shell ls -d */ | grep "^[0-9]\{1,\}_" | sed "s/\/$$//")

TEST = $(shell ls -d */ | grep "^[0-9]\{1,\}_" | sed "s/\/$$//")

all:
	@for i in $(SUBDIR) ; do \
		echo "----------------------------------------"; \
		echo -e "\\e[35mapps: build \\e[36m $$i \\e[0m"; \
		echo "----------------------------------------"; \
		make -C $$i || exit 1; \
	done

clean:
	@for i in $(SUBDIR) ; do \
		echo "----------------------------------------"; \
		echo -e "\\e[35mapps: clean \\e[36m $$i \\e[0m"; \
		echo "----------------------------------------"; \
		make -C $$i clean || exit 1; \
	done

test:
	@echo $(TEST)
	@echo $(SHELL)
