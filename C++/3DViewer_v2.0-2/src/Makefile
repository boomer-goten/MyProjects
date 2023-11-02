UNAME:=$(shell uname -s)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic -D_GNU_SOURCE

SOURCES = *.c
LIBS = -lcheck -lm -lgcov
TEST_FLAGS = -lcheck -lgcov -lm -g

ifeq ($(UNAME), Linux)
	LIBS += -lsubunit
	TEST_FLAGS += -lrt -lpthread -lsubunit
endif

all: clean install

install:
	@-rm -rf build
	@-mkdir build
	@-cd build && qmake ../3D_Viewer_1.pro
	@-make -C ./build
	@-cd build && make clean && rm -f Makefile

uninstall:
	rm -rf build/

dvi:
#texi2dvi 3D_Viewer_manual.texi
#xdvi 3D_Viewer_manual.dvi
	open ./3D_Viewer_manual.html

dist: install
	tar -czf s21_3D_Viewer_1.tar build

tests:
	g++ test/test.cc ModelOperations.cc ReadMethods.cc -o tst --coverage -lgtest -Wall -Wextra -Wextra -std=c++17 -g
	valgrind -s --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./tst


gcov_report: test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info
	rm -f *.gcda *.gcno *.gcov *.info
	open report/index.html

gcov_report1: test
	rm -rf report
	mkdir report
	gcovr -r . --html --html-details -o report/index.html
	rm -rf *.gcda *.gcno
	open report/index.html

check_style:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cc *.h *.cpp headers/*
	rm .clang-format

clang_style:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.cc *.h *.cpp headers/*
	rm .clang-format

valgrind:
	valgrind -s --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./test.out

rebuild: all

clean:
	rm -rf *.gcda *.gcno *.out *.dSYM *.o *.a report test/s21_3dviewer_tests.c s21_3D_Viewer_1.tar *.log *.toc *.aux *.dvi *.pdf
