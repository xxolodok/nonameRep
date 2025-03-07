quadratic.o: quadratic.c
	gcc -g -c quadratic.c -o quadratic.o 

quadratic.a: quadratic.o
	ar rc quadratic.a quadratic.o
quadratic_test.o: quadratic_test.c
	gcc -g -c quadratic_test.c -o quadratic_test.o

quadratic_test: quadratic_test.o quadratic.a
	gcc -g -o quadratic_test quadratic_test.o quadratic.a -lm

 