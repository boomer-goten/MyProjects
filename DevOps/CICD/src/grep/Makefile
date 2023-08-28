CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

CAT_DIR = .
CAT_SRC := $(wildcard $(CAT_DIR)/*.c)
CAT_OBJECTS := $(CAT_SRC:$(CAT_DIR)/%.c=%.o)

GREP_DIR = ../grep
GREP_SRC := $(wildcard $(GREP_DIR)/*.c)
GREP_OBJECTS := $(GREP_SRC:$(GREP_DIR)/%.c=%.o)

CAT_NAME = s21_cat

GREP_NAME = s21_grep

.PHONY: all

all: $(GREP_NAME) $(CAT_NAME)

.PHONY: $(GREP_NAME) clean

$(GREP_NAME): $(GREP_OBJECTS)
	$(CC) $(GREP_SRC) -o $(GREP_DIR)/$@

$(GREP_OBJECTS): $(GREP_SRC)
	$(CC) $(CFLAGS) $(GREP_DIR)/$(GREP_NAME).c -c $(GREP_SRC)


.PHONY: $(CAT_NAME) clean

$(CAT_NAME): $(CAT_OBJECTS)
	$(CC) $(CAT_SRC) -o $(CAT_DIR)/$@

$(CAT_OBJECTS): $(CAT_SRC)
	$(CC) $(CFLAGS) $(CAT_DIR)/$(CAT_NAME).c -c $(CAT_SRC)

.PHONY: clean
clean:
		@rm -rf ../grep/*.o
		@rm -rf *.o

.PHONY: clean_all
clean_all:
		@rm -rf $(CAT_NAME)
		@rm -rf ../grep/$(GREP_NAME)
