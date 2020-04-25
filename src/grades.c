#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "functions.h"

int main(){
	printf("Welcome to %s of the grade calculator.\n", version);
	printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	
	char input[10];
	
	int isValid;
	
	int year;
	int semester;
	int periods;
	
	ERR1: printf("Please enter how many years to include in GPA calculations, not including this year (1-4): ");
	fgets(input, 10, stdin);
	isValid = verify_year(input);
	if(isValid != 0){
		printf("Enter a valid year! ");
		goto ERR1;
	} else {
		year = atoi(input);
	}
	double gradePointsWeight[year];
	double gradePointsUnweight[year];
	double gradePointTotalWeight;
	double gradePointTotalUnweight;
	double creditsTotal;
	ERR2: printf("Please enter what semester of the current year you are on (1-2): ");
	fgets(input, 10, stdin);
	isValid = verify_semester(input);
	if(isValid != 0){
		printf("Enter a valid semester! ");
		goto ERR2;
	} else {
		semester = atoi(input);
	}
	for(int i = 1; i < year; i++){
		for(int j = 0; j < 2; j++){
			int sem = j + 1;
			ERR3: printf("Please enter the number of periods there were in semester %i of year %i (1-8): ", sem, i);
			fgets(input, 10, stdin);
			isValid = verify_classes(input);
			int period;
			if(isValid != 0){
				printf("Enter a valid number of periods! ");
				goto ERR3;
			} else {
				period = atoi(input);
			}
			double semesterGradePointsWeightSum;
			double semesterGradePointsUnweightSum;
			double semesterCreditsSum;
			double semesterGrades[period];
			double semesterRound[period];
			double semesterCredits[period];
			double semesterGradePointsWeight[period];
			double semseterGradePointsUnweight[period];
			int semesterTeachers[period];
			int semesterTypes[period];
			for(int k = 0; k < period; k++){
				int per = k + 1;
				ERR4: printf("%s%i of semester %i of year %i: ", teacher_list_charter, per, sem, i);
				fgets(input, 10, stdin);
				isValid = verify_teachers(input);
				if(isValid != 0){
					printf("Enter a valid teacher! ");
					goto ERR4;
				} else {
					semesterTeachers[k] = atoi(input);
				}
				if(semesterTeachers[k] == 14){
					ERR5: printf("Please enter the point at which the teacher rounds, use 1 if they do not round: ");
					fgets(input, 10, stdin);
					isValid = verify_constants(input);
					if(isValid != 0){
						printf("Please enter a valid rounding point! ");
						goto ERR5;
					} else {
						double semesterRoundTemp = atof(input);
						if(semesterRoundTemp == 1){
							semesterRound[k] = 0;
						} else {
							semesterRound[k] = semesterRoundTemp;
						}
					}
				} else {
					rounding_select(semesterTeachers[k]);
					semesterRound[k] = *roundtemp;
				}
				ERR6: printf("Please enter the grade for period %i of semester %i of year %i as a decimal: ", per, sem, i);
				fgets(input, 10, stdin);
				isValid = verify_grades(input);
				if(isValid != 0){
					printf("Please enter a valid grade! ");
					goto ERR6;
				} else {
					semesterGrades[k] = atof(input);
				}
				ERR7: printf("Please enter the number of credits for period %i of semester %i of year %i: ", per, sem, i);
				fgets(input, 10, stdin);
				isValid = verify_credits(input);
				if(isValid != 0){
					printf("Please enter a valid number of credits! ");
					goto ERR7;
				} else {
					semesterCredits[k] = atof(input);
				}
				ERR8: printf("%s%i of semester %i of year %i: ", class_types, per, sem, i);
				fgets(input, 10, stdin);
				isValid = verify_type(input);
				if(isValid != 0){
					printf("Please enter a valid class type! ");
					goto ERR8;
				} else {
					semesterTypes[k] = atoi(input);
				}
				semesterGradePointWeight[k] = gpa_class(semesterGrades[k], semesterCredits[k], semesterRound[k], semesterTypes[k]);
				semesterGradePointUnweight[k] = gpa_class(semesterGrades[k], semesterCredits[k], semesterRound[k], 1);
			}
			for(int k = 0; k < period; k++){
				gradePointTotalWeight = gradePointTotalWeight + semesterGradePointWeight[k];
				gradePointTotalUnweight = gradePointTotalUnweight + semesterGradePointUnweight[k];
				creditsTotal = creditsTotal + semesterCredits[k];
			}
		}
	}
	ERR9: printf("Please enter the number of periods you have this year (1-8): ");
	isValid = verify_classes(input);
	if(isValid != 0){
		printf("Enter a valid number of periods! ");
		goto ERR9;
	} else {
		periods = atoi(input);
	}
	
	int teachers[periods];
	double q1grades[periods];
	double q2grades[periods];
	double q1weights[periods];
	double q2weights[periods];
	double f1weights[periods];
	double f2weights[periods];
	double f1grades[periods];
	double rounding[periods];
	double credits[periods];
	double types[periods];
	double percentages[periods][11];
	double results[periods][11];
	
	for(int i = 0; i < periods; i++){
		int per = i + 1;
		ERR10: printf("%s%i: ", teacher_list_charter, per);
		fgets(input, 10, stdin);
		isValid = verify_teachers(input);
		if(isValid != 0){
			printf("Enter a valid teacher! ");
			goto ERR10;
		} else {
			teachers[i] = atoi(input);
		}
		if(teachers[i] == 14){
			ERR11: printf("Please enter the weight of the first quarter as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR11;
			} else {
				q1weights[i] = atof(input);
			}
			ERR12: printf("Please enter the weight of the second quarter as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR12;
			} else {
				q2weights[i] = atof(input);
			}
			ERR13: printf("Please enter the weight of the final as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR13;
			} else {
				fweights[i] = atof(input);
			}
			ERR14: printf("Please enter the point that the teacher rounds at, use 1 if they do not round: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid rounding point! ");
				goto ERR14;
			} else {
				double roundTemp = atof(input);
				if(roundTemp == 1){
					rounding[i] = 0;
				} else {
					rounding[i] = atof(input);
				}
			}
		} else {
			q1weight_select(teachers[i]);
			q1weights[i] = *q1temp;
			q2weight_select(teachers[i]);
			q2weights[i] = *q2temp;
			fweight_select(teachers[i]);
			f1weights[i] = *fwtemp;
			if(teachers[i] == 3){
				f2weights[i] = *f1wtemp;
			} else {
				f2weights[i] = 0;
			}
			rounding_select(teachers[i]);
			rounding[i] = *roundtemp;
		}
		ERR15: printf("%sfirst%s", grade1, grade2);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR15;
		} else {
			q1grades[i] = atof(input);
		}
		ERR16: printf("%ssecond%s", grade1, grade2);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR16;
		} else {
			q2grades[i] = atof(input);
		}
		if(teachers[i] == 3){
			ERR17: printf("What is your grade for the first part of the final? ");
			fgets(input, 10, stdin);
			isValid = verify_grades(input);
			if(isValid != 0){
				printf("Enter a valid grade! ");
				goto ERR17;
			} else {
				f1grades[i] = atof(input);
			}
		}
		ERR18: printf("Please enter the number of credits for this class: ");
		fgets(input, 10, stdin);
		isValid = verify_credits(input);
		if(isValid != 0){
			printf("Enter a valid number of credits! ");
			goto ERR18;
		} else {
			credits[i] = atof(input);
		}
		ERR19: printf("%s%i: ", class_types, per);
		fgets(input, 10, stdin);
		isValid = verify_type(input);
		if(isValid != 0){
			printf("Enter a valid class type! ");
			goto ERR19;
		} else {
			types[i] = atoi(input);
		}
