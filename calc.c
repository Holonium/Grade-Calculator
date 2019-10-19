//This file performs the calculations.
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

double finalCalc(double q1grade, double q2grade, double q1weight, double q2weight, double fweight, double target){
	double fgrade = (target - ((q1grade * q1weight) + (q2grade * q2weight))) / fweight;
	return fgrade;
}
double roundCalc(double gradeRaw, double roundingFactor){
	double grade = gradeRaw - roundingFactor;
	return grade;
}
