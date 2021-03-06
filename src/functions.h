#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

double *q1temp;
double *q2temp;
double *fwtemp;
double *roundtemp;
double *f1wtemp;

int verify_YN(char *input);
int verify_years(int input);
int verify_periods(int input);
int verify_grade(double input);
int verify_type(int input);
int verify_credits(double input);
int verify_rounding(double input);
int verify_teacher(int input);
int verify_weight(double input);

double final_calc(double q1grade, double q2grade, double q1weight, double q2weight, double fweight, double target);
double final_calc_multiweight(double q1grade, double q2grade, double f1grade, double q1weight, double q2weight, double f1weight, double f2weight, double target);
double round_calc(double gradeRaw, double roundingFactor);

double q1weight_select(int teacher);
double q2weight_select(int teacher);
double fweight_select(int teacher);
double rounding_select(int teacher);

double gpa_class(double grade, double credits, double rounding, int type);
double gpa_semester(double gradePointSum, double totalCredits);
double gpa_full(double gradePointSum, double totalCredits);

#endif
