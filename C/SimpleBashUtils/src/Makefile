CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

GREP_DIR = ./grep
GREP_SRC := $(wildcard $(GREP_DIR)/*.c)
GREP_OBJECTS := $(GREP_SRC:$(GREP_DIR)/%.c=%.o)

CAT_DIR = ./cat
CAT_SRC := $(wildcard $(CAT_DIR)/*.c)
CAT_OBJECTS := $(CAT_SRC:$(CAT_DIR)/%.c=%.o)

GREP_NAME = s21_grep

CAT_NAME = s21_cat

.PHONY: all

all: $(GREP_NAME) $(CAT_NAME) clean

.PHONY: $(GREP_NAME)

$(GREP_NAME): $(GREP_OBJECTS)
	$(CC) $(GREP_SRC) -o $(GREP_DIR)/$@

$(GREP_OBJECTS): $(GREP_SRC)
	$(CC) $(CFLAGS) $(GREP_DIR)/$(GREP_NAME).c -c $(GREP_SRC)


.PHONY: $(CAT_NAME)

$(CAT_NAME): $(CAT_OBJECTS)
	$(CC) $(CAT_SRC) -o $(CAT_DIR)/$@

$(CAT_OBJECTS): $(CAT_SRC)
	$(CC) $(CFLAGS) $(CAT_DIR)/$(CAT_NAME).c -c $(CAT_SRC)

.PHONY: clean
clean:
		@rm -rf ./cat/*.o
		@rm -rf ./grep/*.o
		@rm -rf *.o

.PHONY: clean_all
clean_all: clean
		@rm -rf ./grep/$(GREP_NAME)
		@rm -rf ./cat/$(CAT_NAME)







# TEST_EXEC = $(TEST_OBJS:%.o=%.out)

# S21_STRING = s21_string.a

# .PHONY: all


# all: $(TEST_OBJS) $(LIB_OBJS) s21_string.a

# $(LIB_OBJS): %.o : $(SOURCE_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 

# $(TEST_OBJS): %.o : $(TEST_DIR)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 

# $(TEST_EXEC): %.out: %.o $(TEST_OBJS)
# 	$(CC) $< $(INCL_LIB) $(LIB_NAME) -o $@ $(CHECK_FLAGS)

# .PHONY: s21_string.a
# s21_string.a: $(LIB_OBJS) 
# 	@ar rc $(LIB_OUT) $(LIB_OBJS)
# 	@ranlib $(LIB_OUT)

# .PHONY: test
# test: s21_string.a build

# build: $(TEST_EXEC)
# 	@for test in $^; do \
# 		./$${test}; \
# 		echo; \
# 	done

# .PHONY: gcov_report
# gcov_report: clean
# 	$(MAKE) -f gcov.mk

# .PHONY: sanitazer
# sanitazer: clean_all
# 	$(MAKE) -f sanit.mk

# .PHONY: clean
# clean:
# 	@find . -name "*.o" -exec rm -f {} \;
# 	@find . -name "*.out" -exec rm -f {} \;
# 	@find . -name "*.gcov" -exec rm -f {} \;
# 	@find . -name "*.gcda" -exec rm -f {} \;
# 	@find . -name "*.gcno" -exec rm -f {} \;
# 	@rm -rf OUT
# 	@rm -f cover.info
# 	@echo "Cleaning..."
# 	@echo "Operation complete :)"

# .PHONY: clean_lib
# clean_lib:
# 	@find . -name "*.a" -exec rm -f {} \;

# .PHONY: clean_all
# clean_all: clean_lib clean
