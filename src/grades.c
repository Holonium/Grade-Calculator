#include <stdio.h>
#include "grades.h"
#include "functions.h"

int main(){

	char input[10];
	int isValid;
	int periods;

	printf("Welcome to %s of the grade calculator.\n", version);
	printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	ERR1: printf("Please enter the number of periods that you wish to calculate grades for (1-8):");
	fgets(input, 10, stdin);
	isValid = verify_classes(input);
	if(isValid != 0){
		printf("Enter a valid number of periods! ");
		goto ERR1;
	} else {
		periods = atoi(input);
	}
	
	int teachers[periods];
	double q1grades[periods];
	double q2grades[periods];
	double q1weights[periods];
	double q2weights[periods];
	double rounding[periods];
	double fweights[periods];
	double fweights1[periods];
	double fgrades1[periods];
	double percentages[periods][11];
	double results[periods][11];
	
	
