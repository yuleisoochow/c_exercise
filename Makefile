
SHELL = /bin/bash

SUBDIR = $(shell ls -d */ | grep "^[0-9]\{1,\}_" | sed "s/\/$$//")

TEST = $(shell ls -d */ | grep "^[0-9]\{1,\}_" | sed "s/\/$$//")

export TARGET_DIR = bin

all:
	$(if $(wildcard $(TARGET_DIR)),, mkdir $(TARGET_DIR))
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
	rm -rf $(TARGET_DIR)	

test:
	@echo $(TEST)
	@echo $(SHELL)
