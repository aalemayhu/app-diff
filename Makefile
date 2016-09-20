#
# This file is copied from udrm[0]
# [0]: https://raw.githubusercontent.com/cherry-pick/udrm/e8f01fdbd536dbfa37082cc5bfce67146dd96ebb/Makefile
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by the
# Free Software Foundation; either version 2.1 of the License, or (at
# your option) any later version.
#

all: app
.PHONY: all

app:
	gcc src/app-diff.c -o bin/app-diff

.PHONY: app

tests:
	$(MAKE) clean -C testing
	CFLAGS="-g -O0" $(MAKE) -C testing/

tt: tests
	testing/app-diff-test
auto-tt:
	fswatch -o testing/test-api.c | xargs -n1 -I{} make tt

.PHONY: tests

.PHONY: tt
