LD_LIBRARY_PATH=.

grades : grades.o teachers.o calc.o validation.o calc.h
	x86_64-w64-mingw32-gcc -m64 -o grades_x64.exe calc.o grades.o teachers.o validation.o calc.h

grades.o : grades.c
	x86_64-w64-mingw32-gcc -m64 -c grades.c
teachers.o : teachers.c
	x86_64-w64-mingw32-gcc -m64 -c teachers.c
calc.o : calc.c
	x86_64-w64-mingw32-gcc -m64 -c calc.c
validation.o : validation.c
	x86_64-w64-mingw32-gcc -m64 -c validation.c

clean :
	rm grades_x64.exe
