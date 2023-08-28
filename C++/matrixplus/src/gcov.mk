CC = gcc
CFLAGS = -Werror -Wextra -Wall -std=c++17 -lstdc++
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lgtest_main -lgtest -pthread -lm -lstdc++
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lgtest_main -lgtest -pthread -lrt -lm -lstdc++
endif
ifeq ($(shell uname -s),Darwin)
	browser = open
endif
ifeq ($(shell uname -s), Linux)
	browser = firefox
endif

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.cc)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.cc=%.o)

SRC_DIR = .
SRC_SRC := $(wildcard $(SRC_DIR)/*.cc)
SRC_OBJS := $(SRC_SRC:%.cc=$(SRC_DIR)/%.o)

EXEC_GCOV = $(TEST_OBJS:%.o=%.out) 

LIB_NAME = s21_matrix_oop.a
INCL_LIB = -L.

GCOV=gcov

all: $(SRC_OBJS) $(EXEC_GCOV) execute build_report

$(EXEC_GCOV): %.out: %.o $(TEST_OBJS)
	$(CC) $(TEST_DIR)/$< $(SRC_DIR)/*.o -o $(TEST_DIR)/$@ $(CHECK_FLAGS) $(GCOV_FLAGS)
	
$(TEST_OBJS): %.o : $(TEST_DIR)/%.cc
	$(CC) $(CFLAGS) -o $(TEST_DIR)/$@ -c $<

$(SRC_OBJS): %.o : $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -o $(SRC_DIR)/$@ -c $< $(GCOV_FLAGS)

execute: $(EXEC_GCOV)
	@for test in $^; do \
		./tests/$${test}; \
		echo; \
	done

build_report:
	@gcov $(SRC_DIR)/*.cc
	@lcov --capture  --directory $(SRC_DIR) --output-file cover.info
	@genhtml cover.info --output-directory OUT
	@$(browser) ./OUT/index.html
	@if [ ! -d $(GCOV) ] ; then mkdir gcov; fi
	@mv *.gcda gcov
	@mv *.gcno gcov
	@mv *.gcov gcov

%:
	@true
