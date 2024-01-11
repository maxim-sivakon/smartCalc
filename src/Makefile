CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -c
TEST_FILE = tests.c
EXECUTABLE = tests
TEST_FLAGS = $(shell pkg-config --cflags --libs check)
GCOV_FLAGS = --coverage $(TEST_FLAGS)
GCOV_DIR = report
GCOV_OBJ_DIR = obj/$(GCOV_DIR)

OS := $(shell uname)


ifeq ($(OS), Linux)
	OPEN=echo 'report: SmartCalc_v1.0-1/src/$(GCOV_DIR)/index.html'
else
	OPEN=open ./$(GCOV_DIR)/index.html
endif

all: clean test install

install: clean
	mkdir build
	qmake && make && make clean && rm Makefile && rm .qmake.stash && mv smartcalc.app build/

uninstall:
	rm -rf build

dist:
	rm -rf Archive_calc_v1.0/
	mkdir Archive_calc_v1.0/
	cp -r ./build/smartcalc.app Archive_calc_v1.0
	tar cvzf Archive_calc_v1.0.tgz Archive_calc_v1.0/
	rm -rf Archive_calc_v1.0/

dvi: 
	makeinfo --html documentation.texi 
	open ./documentation/index.html

gcov_report: check
	mkdir -p $(GCOV_DIR)
	$(CC) $(TEST_FILE) lib/stack.c lib/polishNotation.c lib/creditCalcLib.c lib/depositCalcLib.c -o greport $(GCOV_FLAGS)
	./greport
	lcov -t "test" -o test.info -c -d .
	genhtml -o ./$(GCOV_DIR) test.info
	$(OPEN)

test: stack.o polishNotation.o creditCalcLib.o depositCalcLib.o test.o
	$(CC) test.o stack.o polishNotation.o creditCalcLib.o depositCalcLib.o -o $(EXECUTABLE) $(TEST_FLAGS)
	./$(EXECUTABLE)

check:
	checkmk clean_mode=1 testsProject/headers/*.check testsProject/*.check > $(TEST_FILE)
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.c *.h
	rm .clang-format

stack.o: lib/stack.c
	$(CC) $(CFLAGS) lib/stack.c -o stack.o

polishNotation.o: lib/polishNotation.c
	$(CC) $(CFLAGS) lib/polishNotation.c -o polishNotation.o

creditCalcLib.o: lib/creditCalcLib.c
	$(CC) $(CFLAGS) lib/creditCalcLib.c -o creditCalcLib.o

depositCalcLib.o: lib/depositCalcLib.c
	$(CC) $(CFLAGS) lib/depositCalcLib.c -o depositCalcLib.o

test.o: check
	$(CC) $(CFLAGS) $(TEST_FILE) -o test.o

rebuild: clean all

clean:
	rm -rf $(EXECUTABLE) *.o *.gcda *.gcno *.info $(GCOV_DIR) tests.c greport build documentation