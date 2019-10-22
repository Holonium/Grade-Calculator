#ifndef CALC_H_
#define CALC_H_

void q1weight_select(int teacher, double *weight);
double q2weight_select(int teacher);
double fweight_select(int teacher);
double rounding_select(int teacher);

double finalCalc(double q1grade, double q2grade, double q1weight, double q2weight, double fweight, double target);
double roundCalc(double gradeRaw, double roundingFactor);

int verify_classes(char *input);
int verify_teacher(char *input);
int verify_grades(char *input);

#endif
