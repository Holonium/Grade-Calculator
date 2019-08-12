//Return teacher variables.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

double *teacherRound(int *teachers, double percentagesRaw[]){
	int i;
	int j;
	for(i = 0; i < 6; i++;){
		if(teachers[i] == 1){
			roundingFactor[i] = 0;
		} else if(teachers[i] == 2){
			roundingFactor[i] = 0;
		} else if(teachers[i] == 3){
			roundingFactor[i] = 0.5;
		} else if(teachers[i] == 4){
			roundingFactor[i] = 0.5;
		} else if(teachers[i] == 5){
			roundingFactor[i] = 0.2;
		} else if(teachers[i] == 6){
			roundingFactor[i] = 0.5;
		} else if(teachers[i] == 7){
			roundingFactor[i] = 0;
		} else if(teachers[i] == 8){
			roundingFactor[i] = 0;
		}
	}
	return roundingFactor;
}

double *teacherQweight(int *teachers){
	int i;
	int j;
	for(i = 0; i < 6; i++;){
		if(teachers[i] == 1){
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2]= 0.45;
		} else if(teachers[i] == 2){
			quarterWeight[i][1] = 0.4;
			quarterWeight[i][2] = 0.4;
		} else if(teachers[i] == 3){
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2] = 0.45;
		} else if(teachers[i] == 4){
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2] = 0.45;
		} else if(teachers[i] == 5){
			quarterWeight[i][1] = 0.4;
			quarterWeight[i][2] = 0.4;
		} else if(teachers[i] == 6){
			quarterWeight[i][1] = 0.4;
			quarterWeight[i][2] = 0.4;
		} else if(teachers[i] == 7){
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2] = 0.45;
		} else if(teachers[i] == 8){
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2] = 0.45;
		}
	}
	return quarterWeight;
}


double *teacherFweight(int *teachers){
	int i;
	int j;
	for(i = 0; i < 6; i++;){
		if(teachers[i] == 1){
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 2){
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 3){
			finalWeight[i] = 10;
		} else if(teachers[i] == 4){
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 5){
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 6){
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 7){
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 8){
			finalWeight[i] = 0.1;
		}
	}
	return finalWeight;
}

