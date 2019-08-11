//Calculate grades.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

double *determineFinals(double quarterGrades[6][2], double quarterWeight[6][2], double finalWeight[6]){
	int i;
	int j;
	int k;
	
	double q12grades[6];
	
	for(i = 0; i < 6; i++){
		q12grades[i] = (quarterGrades[i][1] * quarterWeight[i][1]) + (quarterGrades[i][2] * quarterWeight[i][2]);
		for(j = 0; j < 11; j++){
			finals[i][j] = (percentages[i][j] - q12grades[i]) / (finalWeight[i]);
		}
	}
	return finals;
}
double *roundPercents(double roundingFactor[6], double percentagesRaw[]){
	int i;
	int j;
	for(i = 0; i < 6; i++){
		for(j = 0; j < 11; j++){
			percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
		}
	}
	return percentages;
}
