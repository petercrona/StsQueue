CPPFLAGS += -MMD -MP -lpthread -std=gnu99 -g
CPPFLAGS += -Isrc -Wall -pedantic-errors -Werror -Wextra

SOURCEDIR := src
DISTDIR := dist

CC := gcc

SRC := $(shell find $(SOURCEDIR) -name '*.c')

all: .build

.build: .createDistFolder .queue_test .cleanTmpFiles

.createDistFolder:
	@mkdir -p dist

.cleanTmpFiles:
	@find $(SOURCEDIR) -name "*.d" -exec rm {} \;
	@find $(SOURCEDIR) -name "*.o" -exec rm {} \;
	@find $(SOURCEDIR) -name "*~" -exec rm {} \;
	@find $(SOURCEDIR) -name "#*#" -exec rm {} \;

clean: .cleanTmpFiles
	@rm dist -rf

.queue_test: $(SRC:%.c=%.o)
	$(CC) -o $(DISTDIR)/queue_test $^ $(CPPFLAGS)

-include $(SRC:%.c=%.d)
