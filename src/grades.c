//This version implements many new features.
#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "functions.h"
#include "results.h"

int main(){
	char version[] = "v1.0.0a1";
	int periods;
	double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

	char input[10];
	
	int isValid = 0;
	
	printf("Welcome to %s of the grade calculator.\n",version);
	ERR1: printf("Please enter the number of periods that you wish to calculate grades for (1-8):");
	fgets(input, 10, stdin);
	isValid = verifyClasses(input);
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
	double fweights[periods];
	double rounding[periods];
	double percentages[periods][11];
	double results[periods][11];
	
	return 0;
}
