#include <stdio.h>
#include "grades.h"
#include "functions.h"

int main(){

	char input[10];
	int isValid;
	int periods;
	int years;

	printf("Welcome to %s of the grade calculator.\n", version);
	printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	ERR1: printf("Please enter how many years you have been in school for GPA calculations: ");
	fgets(input, 10, stdin);
	isValid = verify_classes(input);
	if(isValid != 0){
		printf("Enter a valid number of years! ");
		goto ERR1;
	} else {
		years = atoi(input);
	}
	ERR2: printf("Please enter the number of periods that you wish to calculate grades for: ");
	fgets(input, 10, stdin);
	isValid = verify_classes(input);
	if(isValid != 0){
		printf("Enter a valid number of periods! ");
		goto ERR2;
	} else {
		periods = atoi(input);
	}
	int periodYears[years];
	for(int i = 0; i < years; i++){
		int j = i + 1;
		ERR3: printf("Please enter the number of periods for year %i: ",j);
		fgets(input, 10, stdin);
		isValid = verify_classes(input);
		if(isValid != 0){
			printf("Enter a valid number of periods! ");
			goto ERR3;
		} else {
			periodYears[i] = atoi(input);
		}
		int k = years - 1;
		if(i == k){
			periodYears[i] = periods;
		}
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
	double credits[years][periods];
	double semesterGrades[years][2][periods];
	double gradePoints[years][periods];
	int types[years][periods];
	
	int m = years - 1;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < periodYears[i]; j++){
			int n = i + 1;
			for(int k = 0; k < 2; k++){
				int l = k + 1;
				ERR4: printf("Please enter your grade for semester %i of year %i: ",l,n);
				fgets(input, 10, stdin);
				isValid = verify_grades(input);
				
