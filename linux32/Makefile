LD_LIBRARY_PATH=.

all: grades.o calc.o gpa.o teachers.o validation.o functions.h
	gcc -m32 -o grades32 grades.o calc.o gpa.o teachers.o validation.o

grades.o: grades.c functions.h
	gcc -m32 -c -o grades.o grades.c

calc.o: calc.c functions.h
	gcc -m32 -c -o calc.o calc.c

gpa.o: gpa.c functions.h
	gcc -m32 -c -o gpa.o gpa.c

teachers.o: teachers.c functions.h
	gcc -m32 -c -o teachers.o teachers.c
	
validation.o: validation.c functions.h
	gcc -m32 -c -o validation.o validation.c
	
clean:
	rm grades32
