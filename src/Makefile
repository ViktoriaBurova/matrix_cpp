G =gcc -lstdc++
GCC =$(G) -Wall -Wextra -Werror -Wuninitialized
LIBS =-lgtest 

all: clean s21_matrix_oop.a test gcove_report

s21_matrix_oop.a: build_s21_matrix

build_s21_matrix:
	$(G) -c s21_*.cc
	ar rcs s21_matrix_oop.a s21_*.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(GCC) s21_matrix_oop.a test.cc -o test $(LIBS)
	./test --gtest_repeat=10 --gtest_break_on_failure
	@make leak

gcove_report: clean
	$(GCC) --coverage test.cc s21_*.cc -o test $(LIBS)
	chmod +x *
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

leak:
	@$(GCC) test.cc s21_*.cc -lgtest -o leaks -g
	CK_FORK=no leaks --atExit -- ./leaks
	@rm ./leaks

clean:
	@rm -rf s21_*o
	@rm -rf *.a
	@rm -rf report
	@rm -rf test
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf *.dSYM