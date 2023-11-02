ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lgtest_main -lgtest -lgcov -lm -pthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lgtest_main -lgtest -pthread -lgcov -lrt -lm -g
endif

CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17 -lm -pedantic --coverage -D_GNU_SOURCE

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.cc)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.cc=%.o)
TEST_EXEC = $(TEST_OBJS:%.o=%.out)

BIN = bin

.PHONY: all
all: clean install

install:
	@mkdir -p build
	@cd build && cmake build ../Maze
	@-make -C ./build
	@ make clean_build

uninstall:
	@rm -rf build/

dvi:
	open ./dvi.html

dist: install
	tar -czf Maze.tar build

.PHONY: test
test: create $(TEST_OBJS) $(LIB_OBJS) build create

create:
	@mkdir -p output

$(TEST_OBJS): %.o : $(TEST_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXEC): %.out: %.o $(TEST_OBJS)
	@if [ ! -d $(BIN) ] ; then mkdir bin; fi
	$(CC) $< -o ./bin/$@ $(CHECK_FLAGS)

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
	@rm -rf coverage.info
	@rm -rf OUT
	@rm -rf report
	@rm -f cover.info
	@rm -rf bin
	@rm -rf build
	@rm -rf *.dSYM *.log *.toc *.aux *.dvi *.pdf
	@rm -rf *.tar
	@rm -rf output
	@echo "Operation complete :)"

.PHONY: clean_build
clean_build:
	@rm -rf ./build/CMakeFiles
	@rm -rf ./build/Maze_autogen
	@rm -rf ./build/*.cmake
	@rm -rf ./build/*.txt

.PHONY: style
style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n --Werror --ferror-limit=1 ./headers/*.h
	@clang-format -n --Werror --ferror-limit=1 ./tests/*.cc
	@clang-format -n --Werror --ferror-limit=1 ./Maze/*.cc
	@clang-format -n --Werror --ferror-limit=1 ./Maze/*.h
	@rm .clang-format

.PHONY: style_fix
style_fix:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -style=Google -i ./headers/*.h --verbose
	@clang-format -style=Google -i ./tests/*.cc --verbose
	@clang-format -style=Google -i ./Maze/*.cc --verbose
	@clang-format -style=Google -i ./Maze/*.h --verbose
	@rm .clang-format

