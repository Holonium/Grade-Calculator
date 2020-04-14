#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int verifyClasses(int periods);
double hsGPA_unweight_class(double qgrade, double credits);
double hsGPA_weight_class(double qgrade, int type, double credits);
double hsGPA_unweight_semester(double gradePointsSum, double totalCredits);
double hsGPA_weight_semester(double gradePointsSum, double totalCredits);
double hsGPA_unweight_full(double gradePoints1, double credits1, double gradePoints2, double credits2, double gradePoints3, double credits3, double gradePoints4, double credits4);
double hsGPA_weight_full(double gradePoints1, double credits1, double gradePoints2, double credits2, double gradePoints3, double credits3, double gradePoints4, double credits4);

#endif
