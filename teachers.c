//This file handles the return of teacher constants.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

double q1weight_select(int teacher){
	double weight;
	if(teacher == 1){
		weight = 0.45;
	} else if (teacher == 2)
	return weight;
}

double q2weight_select(int teacher){
	double weight;
	if(teacher == 1){
		weight = 0.45;
	}
	return weight;
}

double fweight_select(int teacher){
	double weight;
	if(teacher == 1){
		weight = 0.1;
	}
	return weight;
}

double rounding_select(int teacher){
	double round;
	if(teacher == 1){
		round = 0.5;
	}
	return round;
}
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
		} else if(teachers[i] == 3){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 45;
			q2weight[i] = 45;
			finalWeight[i] = 10;
		} else if(teachers[i] == 4){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 5){
			roundingFactor[i] = 0.2;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 6){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 7){
			roundingFactor[i] = 0;
			for(j = 0; j < 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 8){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		}
