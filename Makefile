LD_LIBRARY_PATH=.

grades : grades.o teachers.o calc.o calc.h
	gcc -o grades grades.o teachers.o calc.o

grades.o : grades.c teachers.o calc.o calc.h
	gcc -c -o grades.o grades.c
teachers.o : teachers.c calc.h
	gcc -c -o teachers.o teachers.c
calc.o : calc.c calc.h
	gcc -c -o calc.o calc.c

clean :
	rm grades grades.o teachers.o calc.o
