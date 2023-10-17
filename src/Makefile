FUNC = $(wildcard ./functions/*.c) 
OBJ = $(patsubst ./functions/%.c, ./objects/%.o, $(FUNC))

TEST = $(wildcard ./tests/*.c)
OBJ_TEST = $(patsubst ./tests/%.c, ./tests_objects/%.o, $(TEST))

GCOV_DIR = ./gcov_report
GCOV_OBJ_DIR = $(GCOV_DIR)/gcov_objects
GCOV_OBJ = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(FUNC:.c=.o)))

UNAME_S = $(shell uname -s)
ARCH = $(shell uname -s)

ifeq ($(UNAME_S),Darwin) 
	TEST_LIBS = -lcheck -lm 
endif
ifeq ($(UNAME_S),Linux)
	TEST_LIBS = -lcheck -lm -lsubunit
endif

ifeq ($(ARCH),arm64)
	CC = gcc -arch arm64
endif

ifeq ($(ARCH),x86_64)
	CC = gcc -arch x86_64
endif

CFLAGS = -Wall -Wextra -Werror -std=c11 -Wpedantic -I. 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -g -O0

all: s21_matrix.a test

s21_matrix.a: $(OBJ)
	ar rcs s21_matrix.a $(OBJ)
	ranlib s21_matrix.a

./objects/%.o : ./functions/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ_TEST) s21_matrix.a
	$(CC) $(OBJ_TEST) $(TEST_LIBS) -L. s21_matrix.a -o test.out
	./test.out
./tests_objects/%.o : ./tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@
gcov_report: $(GCOV_OBJ) $(OBJ_TEST)
	$(CC) $(GCOV_FLAGS) $(GCOV_OBJ) $(OBJ_TEST)  \
		-o $(GCOV_DIR)/test_coverage $(TEST_LIBS)
	./$(GCOV_DIR)/test_coverage;
	gcov $(GCOV_OBJ_DIR)/*.gcno;
	@mv *.gcov $(GCOV_OBJ_DIR);
	lcov -c -t "s21_matrix" -o $(GCOV_DIR)/report.info -d $(GCOV_OBJ_DIR) \
		--rc lcov_branch_coverage=1;
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/report.info --rc lcov_branch_coverage=1

$(GCOV_OBJ_DIR)/%.o: ./functions/%.c 
	mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS)  -c $< -o $@

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf ./*/*.o ./*/*.a ./*/*.gcno ./*/*.gcda ./*/*.info ./*/*.out ./*/*.gcov
	rm -rf ./gcov_report

format:
	-mv ../materials/linters/.clang-format ./
	clang-format -n ./*/*.c ./*/*.h ./*.h
	clang-format -i ./*/*.c ./*/*.h ./*.h
	clang-format -n ./*/*.c ./*/*.h ./*.h
	-mv ./.clang-format ../materials/linters/

rebuild: clean all

.PHONY: all test gcov_report
