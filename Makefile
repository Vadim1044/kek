clear:
	@rm -rf *.o *.a *_test

fmt:
	@clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

cFmt:
	@clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

roots.o: roots.c roots.h
	gcc -g -c roots.c -o roots.o

roots.a: roots.o
	ar rc roots.a roots.o

roots_test.o: roots_test.c roots.h
	gcc -g -c roots_test.c -o roots_test.o

roots_test: roots_test.o roots.a
	gcc -g -o roots_test roots_test.o roots.a  -lm


test: roots_test
	./roots_test

integral.o: integral.c integral.h
	gcc -g -c integral.c -o integral.o

integral.a: integral.o
	ar rc integral.a integral.o

integral_test.o: integral_test.c integral.h
	gcc -g -c integral_test.c -o integral_test.o

integral_test: integral_test.o integral.a
	gcc -g -o integral_test integral_test.o integral.a -lm


test: integral_test
	./integral_test

test: test_list

list.o: list.c list.h
	gcc -g -c list.c -o list.o

list.a: list.o
	ar rc list.a list.o

test_list.o: test_list.c list.h
	gcc -g -c test_list.c -o test_list.o

test_list: test_list.o list.a
	gcc -g -o test_list test_list.o list.a 

stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

stack_test.o: stack_test.c stack.h
	gcc -g -c stack_test.c -o stack_test.o

stack_test: stack_test.o stack.a
	gcc -g -o stack_test stack_test.o stack.a 


test: stack_test
	./stack_test
