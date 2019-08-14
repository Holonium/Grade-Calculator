#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
//Declaration of input and calibration characters.
	char *y = malloc(2);
	char *n = malloc(2);
	char *weighting = malloc(2);
	char *rounding = malloc(2);
	char *eight = malloc(2);
	char *five = malloc(2);
//Declaration of mathematical constants.
	double letters[] = {93,90,87,83,80,77,73,70,67,63,60};
	double lettersRounded[10];
//Declarations of output character chunks.
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
//Definition of output constants.
	y = "Y";
	n = "N";
	char does[] = "Does your teacher ";
	
	double roundingFactor;
	double q1raw;
	double q2raw;
	double q1w;
	double q2w;
	double fw;
	double q12;
	double final;

	int rounding1 = 0;
	int rounding2 = 0;
//error chars
	printf("Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class.\n");
	printf("To use this program, use Y for yes, and N for no. Grades and weights should be entered in percents.\n");
	printf("%sweigh your final separate from the quarters? ", does);
	fgets(weighting, 2, stdin);
	if(strcmp(weighting, n) == 0){
		goto errors;
	}
	printf("%sround? ",does);
	fgets(rounding, 2, stdin);
	if(strcmp(rounding, n) == 0){
		roundingFactor = 0;
		goto round;
	}
	printf("%sround at 0.5? ",does);
	fgets(five,2,stdin);
	if(strcmp(five, calibrationy) == 0){
		roundingFactor = 0.5;
		goto round;
	} else {
		rounding1 = 1;
	}
	printf("%sround at 0.8? ",does);
	fgets(eight,2,stdin);
	if(strcmp(rounding,y) == 0){
		roundingFactor = 0.2;
		goto round;
	} else {
		rounding2 = 1;
	}
	if(rounding
	

	
errors:
	return 0;
}
