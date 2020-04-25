#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "functions.h"

int main(){
	printf("Welcome to %s of the grade calculator.\n", version);
	printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	
	char input[10];
	
	int isValid;
	int years;
	int semester;
	int periods;
	double 
	
	int teachers[4][2][8];
	int types[4][2][8];
	int periodsPast[4][2];
	double gradesPast[4][2][8];
	double roundingPast[4][2][8];
	double gradePointsWeightPast[4][2][8];
	double gradePointsUnweightPast[4][2][8];
	double credits[4][2][8];
	double qgrades[2][8];
	double weights[4][8];
	double rounding[8];
	double percentages[8][11];
	double results[8][11];
	
	ERR1: printf("Please enter the number of years that you have completed (1-3): ");
	fgets(input, 10, stdin);
	isValid = verify_year(input);
	if(isValid != 0){
		printf("Enter a valid number of years! ");
		goto ERR1;
	} else {
		years = atoi(input);
	}
	
	for(int i = 0; i < years; i++){
		int year = i + 1;
		for(int j = 0; j < 2; j++){
			int sem = j + 1;
			ERR2: printf("Please enter the number of periods you had for semester %i of year %i (1-8): ", year, sem);
			fgets(input, 10, stdin);
			isValid = verify_classes(input);
			if(isValid != 0){
				printf("Enter a valid number of periods! ");
				goto ERR2;
			} else {
				periodsPast[i][j] = atoi(input);
			}
			for(int k = 0; k < periodsPast[i][j]; k++){
				int per = k + 1;
				ERR3: printf("%s%i of semester %i of year %i: ", teacher_list_charter, per, sem, year);
				fgets(input, 10, stdin);
				isValid = verify_teachers(input);
				if(isValid != 0){
					printf("Enter a valid teacher! ");
					goto ERR3;
				} else {
					teachers[i][j][k] = atoi(input);
				}
				if(teachers[i][j][k] == 14){
					ERR4: printf("Please enter the point that the teacher rounds at, using 1 of they do not round: ");
					fgets(input, 10, stdin);
					isValid = verify_constants(input);
					if(isValid != 0){
						printf("Enter a valid rounding point! ");
						goto ERR4;
					} else {
						double temp = atof(input);
						if(temp == 1){
							roundingPast[i][j][k] = 0;
						} else {
							roundingPast[i][j][k] = 1 - temp;
						}
					}
				} else {
					rounding_select(teachers[i][j][k]);
					roundingPast[i][j][k] = *roundtemp;
				}
				ERR5: printf("%s%i of semester %i of year %i (1-3): ", class_types, per, sem, year);
				fgets(input, 10, stdin);
				isValid = verify_type(input);
				if(isValid != 0){
					printf("Please enter a valid class type! ");
					goto ERR5;
				} else {
					types[i][j][k] = atoi(input);
				}
				ERR6: printf("Please enter the number of credits the class was worth: ");
				fgets(input, 10, stdin);
				isValid = verify_credits(input);
				if(isValid != 0){
					printf("Enter a valid number of credits! ");
					goto ERR6;
				} else {
					credits[i][j][k] = atof(input);
				}
				ERR7: printf("Please enter the grade for the semester as a decimal: ");
				fgets(input, 10, stdin);
				isValid = verify_grades(input);
				if(isValid != 0){
					printf("Enter a valid grade! ");
					goto ERR7;
				} else {
					gradesPast[i][j][k] = atof(input);
				}
				gradePointsWeightPast[i][j][k] = gpa_class(gradesPast[i][j][k], credits[i][j][k], roundingPast[i][j][k], types[i][j][k]);
				gradePointsUnweightPast[i][j][k] = gpa_class(gradesPast[i][j][k], credits[i][j][k], roundingPast[i][j][k], 1);
			}
		}
	}
	ERR8: printf("Please enter the semester that is currently in progress (1-2): ");
	fgets(input, 10, stdin);
	isValid = verify_semester(input);
	if(isValid != 0){
		printf("Enter a valid semester! ");
		goto ERR8;
	} else {
		semester = atoi(input);
	}
	if(semester == 2){
		ERR9: printf("Please enter the number of periods you had for semester 1 of the current year (1-8): ");
		fgets(input, 10, stdin);
		isValid = verify_classes(input);
		if(isValid != 0){
			printf("Enter a valid number of periods! ");
			goto ERR9;
		} else {
			periodsPast[4][0] = atoi(input);
		}
		for(int i = 0; i < periodsPast[4][0]; i++){
			int per = i + 1;
			int year = years + 1;
			ERR10: printf("%s%i of semester 1 of the current year: ", teacher_list_charter, per);
			fgets(input, 10, stdin);
			isValid = verify_teachers(input);
			if(isValid != 0){
				printf("Enter a valid teacher! ");
				goto ERR10;
			} else {
				teachers[years][0][i] = atoi(input);
			}
			if(teachers[years][0][i] == 14){
				ERR11: printf("Please enter the point that the teacher rounds at, using 1 of they do not round: ");
				fgets(input, 10, stdin);
				isValid = verify_constants(input);
				if(isValid != 0){
					printf("Enter a valid rounding point! ");
					goto ERR11;
				} else {
					double temp = atof(input);
					if(temp == 1){
						roundingPast[years][0][i] = 0;
					} else {
						roundingPast[years][0][i] = 1 - temp;
					}
				}
			} else {
				rounding_select(teachers[years][0][i]);
				roundingPast[years][0][i] = *roundtemp;
			}
			ERR12: printf("%s%i of semester 1 of the current year: ", class_types, per);
			fgets(input, 10, stdin);
			isValid = verify_type(input);
			if(isValid != 0){
				printf("Enter a valid class type! ");
				goto ERR12;
			} else {
				types[years][0][i] = atoi(input);
			}
			ERR13: printf("Please enter the number of credits the class was worth: ");
			fgets(input, 10, stdin);
			isValid = verify_credits(input);
			if(isValid != 0){
				printf("Enter a valid number of credits! ");
				goto ERR13;
			} else {
				credits[years][0][i] = atof(input);
			}
			ERR14: printf("Please enter the grade for the semester as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_grades(input);
			if(isValid != 0){
				printf("Enter a valid grade! ");
				goto ERR14;
			} else {
				gradesPast[years][0][i] = atof(input);
			}
			gradePointsWeightPast[years][0][i] = gpa_class(gradesPast[years][0][i], credits[years][0][i], roundingPast[years][0][i], types[years][0][i]);
				gradePointsUnweightPast[i][j][k] = gpa_class(gradesPast[years][0][i], credits[years][0][i], roundingPast[years][0][i], 1);
		}
		
