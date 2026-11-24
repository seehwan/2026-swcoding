# Build, run, or clean every week's lecture examples from one place.
# Command-line overrides, such as CFLAGS=..., pass through to recursive make.

EXAMPLE_DIRS = week01-struct/examples \
               week02-operators/examples \
               week03-linked-list/examples \
               week04-file-io-project/examples \
               optional/a-circular-list/examples \
               optional/b-intrusive-list/examples \
               optional/c-container-of/examples

all: $(EXAMPLE_DIRS)

$(EXAMPLE_DIRS):
	$(MAKE) -C $@

run:
	@set -e; for directory in $(EXAMPLE_DIRS); do \
		$(MAKE) -C "$$directory" run; \
	done

clean:
	@set -e; for directory in $(EXAMPLE_DIRS); do \
		$(MAKE) -C "$$directory" clean; \
	done

.PHONY: all run clean $(EXAMPLE_DIRS)
