include config.mk

SRC=ssnake.c util.c
OBJ=$(SRC:.c=.o)
OUT=snake

all: config.h config.mk $(OBJ)
	$(CC) $(LDFLAGS) -o $(OUT) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

config.h:
	@if [ ! -f config.h ]; then \
		echo "cp config.def.h $@"; \
		cp config.def.h $@; \
	fi

install:
	install -m 755 $(OUT) $(INSTALL_PREFIX)/bin

uninstall:
	rm $(INSTALL_PREFIX)/bin/$(OUT)

clean:
	rm $(OUT) $(OBJ)

.PHONY: clean install uninstall
