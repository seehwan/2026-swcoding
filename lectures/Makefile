# Build, run, or clean every session's lecture examples from one place.
# Command-line overrides, such as CFLAGS=..., pass through to recursive make.

EXAMPLE_DIRS = session1-struct/examples \
               session2-operators/examples \
               session3-linked-list/examples \
               session4-file-io-project/examples \
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
