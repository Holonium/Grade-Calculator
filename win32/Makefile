LD_LIBRARY_PATH=.

grades : grades.o teachers.o calc.o validation.o calc.h
	i686-w64-mingw32-gcc -m32 -o grades_x32.exe calc.o grades.o teachers.o validation.o calc.h

grades.o : grades.c
	i686-w64-mingw32-gcc -m32 -c grades.c
teachers.o : teachers.c
	i686-w64-mingw32-gcc -m32 -c teachers.c
calc.o : calc.c
	i686-w64-mingw32-gcc -m32 -c calc.c
validation.o : validation.c
	i686-w64-mingw32-gcc -m32 -c validation.c

clean :
	rm grades_x32.exe
