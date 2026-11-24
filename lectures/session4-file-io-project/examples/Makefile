# Session 4 lecture examples: file I/O (Part 1) and multi-file programs (Part 2).
#   make          build both sets
#   make run      run every example with prepared input
#   make test     run the file-based tests of Part 1
#   make clean    remove the executables and generated files

EXAMPLE_DIRS = file-io multi-file

all: $(EXAMPLE_DIRS)

$(EXAMPLE_DIRS):
	$(MAKE) -C $@

run:
	@set -e; for directory in $(EXAMPLE_DIRS); do \
		$(MAKE) -C "$$directory" run; \
	done

test:
	$(MAKE) -C file-io test

clean:
	@set -e; for directory in $(EXAMPLE_DIRS); do \
		$(MAKE) -C "$$directory" clean; \
	done

.PHONY: all run test clean $(EXAMPLE_DIRS)
