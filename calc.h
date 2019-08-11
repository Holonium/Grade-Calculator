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

int *Percents
int *Grades

//Teacher variables
int teachers[6];
int range;

//Strings
char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

char *guaranteed1 = "You are guaranteed to get at least an ";
char *guaranteed2 = "You are guaranteed to get at least a ";
char *guaranteed3 = " for the semester!";
char *grade1 = "What is your grade for the ";
char *grade2 = " quarter of this semester? ";
char *out1 = "You need at least a ";
char *out2 = "%% to get a ";
char *out3 = " for this semester.";
char *welcome = "Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class.";
char *teacher_list = "Please enter the number of the teacher: ";

//Functions
int validateTeacher(int teachers[6], int range);
double *roundPercents(double roundingFactor[6], double percentagesRaw[]);
double *determineFinals(double quarterGrades[6][2], double quarterWeight[6][2], double finalWeight[6]);

#endif
