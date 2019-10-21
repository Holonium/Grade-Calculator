LD_LIBRARY_PATH=.

grades : grades.o teachers.o calc.o validation.o calc.h
	gcc -o grades grades.o teachers.o calc.o validation.o

grades.o : grades.c calc.h
	gcc -c -o grades.o grades.c
teachers.o : teachers.c calc.h
	gcc -c -o teachers.o teachers.c
calc.o : calc.c calc.h
	gcc -c -o calc.o calc.c
validation.o : validation.c calc.h
	gcc -c -o validation.o validation.c

clean :
	rm grades grades.o teachers.o calc.o validation.o
