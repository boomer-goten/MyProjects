#UNAME = $(shell uname -s)
#CHECK_FLAGS = -lcheck -lm -lpthread
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11 -lm -pedantic -export-dynamic `pkg-config --cflags --libs gtk+-3.0`
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage
APP = build/Calculator.app

LIB_OUT = s21_calculator.a
LIB_NAME = s21_calculator.a
INCL_LIB = -L.

SOURCE_DIR = .
LIB_SRC := $(wildcard $(SOURCE_DIR)/*.c)
LIB_OBJS := $(LIB_SRC:$(SOURCE_DIR)/%.c=%.o)

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.c=%.o)

TEST_EXEC = $(TEST_OBJS:%.o=%.out)

S21_DECIMAL = s21_calculator.a

BIN = bin

.PHONY: all


all: $(TEST_OBJS) $(LIB_OBJS) install

$(LIB_OBJS): %.o : $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_OBJS): %.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_EXEC): %.out: %.o $(TEST_OBJS)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	$(CC) $< $(INCL_LIB) $(LIB_NAME) -o ./bin/$@ $(CHECK_FLAGS)

.PHONY: install
install: $(LIB_OBJS) 
	@if [ ! -d build ] ; then mkdir build; fi
	@cp 1.glade ./build/1.glade
	$(CC) $(LIB_OBJS) $(CFLAGS) -o $(APP)
	$(MAKE) -f Makefile clean


.PHONY: uninstall
uninstall:
	@if [ -d build ] ; then rm -rf build; fi

.PHONY: dvi
dvi:
	open dvi.html

.PHONY: test
test: s21_calculator.a build

build: $(TEST_EXEC)
	@for test in $^; do \
		./bin/$${test}; \
		echo; \
	done

.PHONY: dist
dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	cp Makefile *.c *.h *.glade *.html *.mk Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	rm -rf Archive_SmartCalc_v1.0/



.PHONY: gcov_report
gcov_report: clean
	$(MAKE) -f gcov.mk

.PHONY: valgrind
valgrind: s21_calculator.a $(TEST_EXEC)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	@for test in ./bin/$^; do \
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/$${test} \
		2> ./bin/$${test}.txt; \
		echo; \
	done

.PHONY: clean
clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@find . -name "*.gcov" -exec rm -f {} \;
	@find . -name "*.gcda" -exec rm -f {} \;
	@find . -name "*.gcno" -exec rm -f {} \;
	@find . -name "*.txt" -exec rm -f {} \;
	@rm -rf OUT
	@rm -f cover.info
	@rm -rf gcov
	@rm -rf bin
	@echo "Cleaning..."
	@echo "Operation complete :)"

.PHONY: clean_lib
clean_lib:
	@find . -name "*.a" -exec rm -f {} \;
	@if [ -d build ] ; then rm -rf build; fi

.PHONY: clean_all
clean_all: clean_lib clean

.PHONY: style
style:
	@clang-format -n --Werror --ferror-limit=1 *.[ch]

