#ifndef CALC_H_
#define CALC_H_

//Teacher functions, see teachers.c in final
int validateInput(int input,int range);
double detQuarterWeight1(int input);
double detQuarterWeight2(int input);
double detFinalWeight(int input);
double detRoundingFactor(int input);

//Mathematical functions, see calc.c in final
double round(double roundingFactor,double percentagesRaw);
double weightQuarters(double quarterWeight1, double quarterWeight2, double quarterGrade1, double quarterGrade2);
double detFinal(double weighted, double percentage, double finalWeight);
#endif
