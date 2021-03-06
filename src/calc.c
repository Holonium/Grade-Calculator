#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

double final_calc(double q1grade, double q2grade, double q1weight, double q2weight, double fweight, double target){
	double fgrade = (target - ((q1grade * q1weight) + (q2grade * q2weight))) / fweight;
	return fgrade;
}

double final_calc_multiweight(double q1grade, double q2grade, double f1grade, double q1weight, double q2weight, double f1weight, double f2weight, double target){
	double fgrade = (target - ((q1grade * q1weight) + (q2grade * q2weight) + (f1grade * f1weight))) / f2weight;
	return fgrade;
}

double round_calc(double gradeRaw, double roundingFactor){
	double grade = gradeRaw - roundingFactor;
	return grade;
}
