LD_LIBRARY_PATH=.

grades : grades.o teachers.o calc.o *.c
	gcc -o grades grades.o teachers.o calc.o grades.c teachers.c calc.c

grades.o : grades.c teachers.o calc.o calc.h
	gcc -o grades.o grades.c teachers.c calc.c
teachers.o : grades.c teachers.c calc.c calc.h
	gcc -o teachers.o teachers.c grades.c calc.c
calc.o : grades.c calc.c teachers.c calc.h
	gcc -o calc.o calc.c grades.c teachers.c

clean :
	rm grades grades.o teachers.o calc.o
