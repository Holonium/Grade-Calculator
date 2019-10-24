grades : calc.o teachers.o validation.o grades.o
	cc -o grades calc.o teachers.o validation.o grades.o
calc.o : calc.c calc.h
	cc -c calc.c
teachers.o : teachers.c calc.h
	cc -c teachers.c
validation.o : validation.c calc.h
	cc -c validation.c
grades.o : grades.c calc.h
	cc -c grades.c
clean :
	rm *.o
