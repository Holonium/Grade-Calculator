#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int verify_YN(char *input){
	char *Y = malloc(2 * sizeof(char));
	strcpy(Y, "Y");
	char *N = malloc(2 * sizeof(char));
	strcpy(N, "N");
	if(strcmp(input, Y) == 0){
		free(Y);
		free(N);
		return 1;
	} else if(strcmp(input, N) == 0){
		free(Y);
		free(N);
		return 2;
	} else {
		free(Y);
		free(N);
		return 0;
	}
}

int verify_years(int input){
	if(input > 3 || input < 1){
		return 1;
	}
	return 0;
}

int verify_periods(int input){
	if(input > 8 || input < 1){
		return 1;
	}
	return 0;
}

int verify_grade(double input){
	if(input < 0){
		return 1;
	}
	return 0;
}

int verify_type(int input){
	if(input < 1 || input > 3){
		return 1;
	}
	return 0;
}

int verify_credits(double input){
	if(input <= 0){
		return 1;
	}
	return 0;
}

int verify_rounding(double input){
	if(input < 0 || input >= 1){
		return 1;
	}
	return 0;
}
