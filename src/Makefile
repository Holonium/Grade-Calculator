LD_LIBRARY_PATH=.

grades: grades.o calc.o gpa.o teachers.o validation.o functions.h grades.h
	gcc -fsanitize=address,undefined -g -m64 -o grades grades.o calc.o gpa.o teachers.o validation.o

grades.o: grades.c functions.h grades.h
	gcc -fsanitize=address,undefined -g -m64 -c -o grades.o grades.c

calc.o: calc.c functions.h
	gcc -fsanitize=address,undefined -g -m64 -c -o calc.o calc.c

gpa.o: gpa.c functions.h grades.h
	gcc -fsanitize=address,undefined -g -m64 -c -o gpa.o gpa.c

teachers.o: teachers.c functions.h
	gcc -fsanitize=address,undefined -g -m64 -c -o teachers.o teachers.c
	
validation.o: validation.c functions.h
	gcc -fsanitize=address,undefined -g -m64 -c -o validation.o validation.c
	
clean:
	rm grades
