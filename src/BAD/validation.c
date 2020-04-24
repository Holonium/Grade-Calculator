#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int verifyClasses(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify < 1){
		return 1;
	}
	return 0;
}

int verifyTeacher(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify > 14){
		return 1;
	} else if(verify < 1){
		return 1;
	}
	return 0;
}

int verifyGrades(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 1;
	} else if(verify < 0){
		return 1;
	}
	return 0;
}
int verifyConstants(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 0;
	} else if(verify < 0){
		return 1;
	} else if(verify > 1){
		return 1;
	}
	return 0;
}
int verifyCredits(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 0;
	} else if(verify < 0){
		return 1;
	}
	return 0;
}
