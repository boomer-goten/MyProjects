ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lgtest_main -lgtest -lgcov -lm -pthread
endif								
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lgtest_main -lgtest -pthread -lgcov -lrt -lm
endif

CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17 -lm -pedantic --coverage -D_GNU_SOURCE

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.cc)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.cc=%.o)
TEST_EXEC = $(TEST_OBJS:%.o=%.out)

BIN = bin

.PHONY: all
all: clean install $(TEST_OBJS) $(LIB_OBJS)

$(LIB_OBJS): %.o : $(SOURCE_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJS): %.o : $(TEST_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_EXEC): %.out: %.o $(TEST_OBJS)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	$(CC) $< -o ./bin/$@ $(CHECK_FLAGS)

install:
	@-rm -rf build
	@-mkdir build
	@-cd build && qmake ../Calculator.pro
	@-make -C ./build
	@ make clean_build

uninstall:
	@rm -rf build/

dvi:
	open ./dvi.html

dist: install
	tar -czf Archive_SmartCalc_v2.0-1.tar build

.PHONY: test
test: build 

build: $(TEST_EXEC)
	@for test in $^; do \
		./bin/$${test}; \
		echo; \
	done

gcov_report: test
	@lcov --capture  --no-external --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory report
	@open report/index.html

.PHONY: valgrind
valgrind: $(TEST_EXEC)
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
	@rm -rf coverage.info
	@rm -rf OUT
	@rm -rf report
	@rm -f cover.info
	@rm -rf gcov
	@rm -rf bin
	@rm -rf .clang-format
	@rm -rf build
	@rm -rf *.dSYM Calculator.tar *.log *.toc *.aux *.dvi *.pdf
	@rm -rf *.tar
	@echo "Operation complete :)"

.PHONY: clean_build
clean_build:
	@rm -rf ./build/*cpp
	@rm -rf ./build/*h
	@rm -rf ./build/.qmake.stash
	@rm -rf ./build/*.o
	@rm -rf ./build/Makefile
	@echo "Operation complete :)"


.PHONY: style
style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n --Werror --ferror-limit=1 ./*.cc
	@clang-format -n --Werror --ferror-limit=1 ./headers/*.h
	@clang-format -n --Werror --ferror-limit=1 ./tests/*.cc

.PHONY: style_fix
style_fix:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -style=Google -i ./*.cc --verbose
	@clang-format -style=Google -i ./headers/*.h --verbose
	@clang-format -style=Google -i ./tests/*.cc --verbose