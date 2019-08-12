//Calculate grades.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int *roundPercents(int *percentsRaw, int *roundingFactors, int *percents){
	int i;
	int j;
	
	for(i = 0; i < 6; i++){
		for(j = 0; j < 11; j++){
			percents[i][j] = percentsRaw[j] - roundingFactors[i];
		}
	}
	return percents;
}
			
int *determineFinals(int *q12grades, int *finalWeight, int *finals){

int *combineQuarters(int *quarterWeight, int *quarterGrade, int *q12grades){

