//Calculate grades.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int determineFinals(double quarterGrades[][], double quarterWeight[][], double finalWeight[]){
	for(i = 0; i < 6; i++){
		for(j = 0; j < 11; j++){
			finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
		}
	}
	return 0;
}
