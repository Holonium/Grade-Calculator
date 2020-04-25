#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

double *q1temp;
double *q2temp;
double *fwtemp;
double *roundtemp;
double *f1wtemp;

int verify_teachers(char *input);
int verify_classes(char *input);
int verify_grades(char *input);
int verify_constants(char *input);
int verify_credits(char *input);
int verify_final(char *input);
int verify_type(char *input);
int verify_year(char *input);
int verify_semester(char *input);

double final_calc(double q1grade, double q2grade, double q1weight, double q2weight, double fweight, double target);
double final_calc_multiweight(double q1grade, double q2grade, double f1grade, double q1weight, double q2weight, double f1weight, double f2weight, double target);
double round_calc(double gradeRaw, double roundingFactor);

void q1weight_select(int teacher);
void q2weight_select(int teacher);
void fweight_select(int teacher);
void rounding_select(int teacher);

double gpa_class(double qgrade, double credits, double rounding, int type);
double gpa_semester(double gradePointSum, double totalCredits);
double gpa_full(double gradePointSum, double totalCredits);

#endif
