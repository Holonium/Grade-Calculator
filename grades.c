//This version implements multiple files in order to reduce size, as well as a custom header. Capabilities will be similar to those of v7. This is the main file.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int main(void){
	int i;
	int j;
	
	for(i = 0; i < 6; i++){
		printf("%s", teacher_list);
		scanf("%d", &teachers[i]);
		
		validateTeacher(teachers);
	}		
		//Put teachers here...

		if(teachers[i] == 1){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 2){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		}
		printf("%sfirst%s", grade1, grade2);
		scanf("%lf", &quarterGrades[i][1]);
		printf("%ssecond%s", grade1, grade2);
		scanf("%lf", &quarterGrades[i][2]);
		q12grade[i] = (q1grades[i] * q1weight[i]) + (q2grades[i] * q2weight[i]);
		//Calculate necessary grades.
		determineFinals(quarterGrades, quarterWeight, finalWeight);
		for(j = 0; j < 11; j++){
			finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
		}
	}
