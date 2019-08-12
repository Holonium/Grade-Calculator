#ifndef CALC_H_
#define CALC_H_

//Percentage variables
double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
double percentages[6][11];
double quarterGrades[6][2];
double quarterWeight[6][2];
double finalWeight[6];
double roundingFactor[6];

double finals[6][11];

//Pointers for return.

int *Percents;
int *Grades;

//Teacher variables
int *teachers;
int range;

//Strings
char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

//Functions
int validateTeacher(int teachers[6], int range);
double *roundPercents(double roundingFactor[6], double percentagesRaw[]);
double *determineFinals(double quarterGrades[6][2], double quarterWeight[6][2], double finalWeight[6]);

#endif
