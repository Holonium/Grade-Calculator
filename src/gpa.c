#include <stdio.h>
#include "functions.h"
#include "grades.h"

const double gpa = 4.00;

double gpa_class(double grade, double credits, double rounding, int type){
	double unmod;
	double percentages[11];
	for(int i = 0; i < 11; i++){
		percentages[i] = round_calc(percentagesRaw[i], rounding);
	}
	for(int i = 0; i < 11; i++){
		int j = i + 1;
		if(i == 0){
			if(grade >= percentages[i]){
				unmod = gpa;
				i = 11;
			}
		} else if(i > 0){
			if(grade >= percentages[j] && grade < percentages[i]){
				unmod = gpa - (i / 3);
				i = 11;
			}
		}
	}
	if(type == 1){
		unmod = unmod + 0;
	} else if(type == 2){
		unmod = unmod + 0.5;
	} else if(type == 3){
		unmod = unmod + 1;
	}
	double gradePoints = unmod * credits;
	return gradePoints;
}

double gpa_semester(double gradePointSum, double totalCredits){
	double GPA = gradePointSum / totalCredits;
	return GPA;
}

double gpa_full(double gradePointSum, double totalCredits){
	double GPA = gradePointSum / totalCredits;
	return GPA;
}
