//This file handles the verification of inputs and error handling.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int verify_classes(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify > 8){
		return 1;
	} else if(verify < 1){
		return 1;
	}
	return 0;
}

int verify_teacher(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify > 13){
		return 1;
	} else if(verify < 1){
		return 1;
	}
	return 0;
}

int verify_grades(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 1;
	} else if(verify < 0){
		return 1;
	}
	return 0;
}
