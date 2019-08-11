grades.o : grades.c calc.o teachers.o validation.o calc.h
	gcc -o grades.o grades.c
calc.o : calc.c calc.h
	gcc -o calc.o calc.h
teachers.o : teachers.c calc.h
	gcc -o teachers.o teachers.c
validation.o : validation.c calc.h
	gcc -o validation.o validation.c
clean :
	rm *.o
