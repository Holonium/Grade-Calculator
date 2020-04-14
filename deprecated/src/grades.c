//This version implements multiple files, support for up to 8 classes, more teachers, a custom header, and an updated style.
//v8.02 adds the option for other teachers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(){
	double version = 8.02;
	int periods;
	double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

	char input[10];
	
	int isValid;

	printf("Welcome to v%.2f of the grade calculator.\n",version);
	ERR1: printf("Please enter the number of periods that you wish to calculate grades for (1-8):");
	fgets(input, 10, stdin);
	isValid = verify_classes(input);
	if(isValid != 0){
		printf("Enter a valid number of periods! ");
		goto ERR1;
	} else {
		periods = atoi(input);
	}

	int teachers[8];
	double q1grades[8];
	double q2grades[8];
	double q1weights[8];
	double q2weights[8];
	double fweights[8];
	double rounding[8];
	double percentages[8][11];
	double results[8][11];

	for(int i = 0; i < periods; i++){
		char *teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\n14) Other\nPlease enter the number of the teacher for period ";
		int period = i + 1;
		ERR2: printf("%s%i: ",teacher_list,period);
		fgets(input, 10, stdin);
		isValid = verify_teacher(input);
		if(isValid != 0){
			printf("Enter a valid teacher! ");
			goto ERR2;
		} else {
			teachers[i] = atoi(input);
		}
		int temp = teachers[i];
		if(temp == 14){
			ERR5: printf("Please enter the weight of the first quarter as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR5;
			} else {
				q1weights[i] = atof(input);
			}
			ERR6: printf("Please enter the weight of the second quarter as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR6;
			} else {
				q2weights[i] = atof(input);
			}
			ERR7: printf("Please enter the weight of the final as a decimal: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid weight! ");
				goto ERR7;
			} else {
				fweights[i] = atof(input);
			}
			ERR8: printf("Please enter the point that the teacher rounds at: ");
			fgets(input, 10, stdin);
			isValid = verify_constants(input);
			if(isValid != 0){
				printf("Enter a valid rounding point! ");
				goto ERR8;
			} else {
				rounding[i] = atof(input);
			}
		} else {
			q1weight_select(temp);
			q1weights[i] = *q1temp;
			q2weight_select(temp);
			q2weights[i] = *q2temp;
			fweight_select(temp);
			fweights[i] = *fwtemp;
			rounding_select(temp);
			rounding[i] = *roundtemp;
		}
		char *grade1 = "What is your grade for the ";
		char *grade2 = " quarter of this semester? ";
		
		ERR3: printf("%sfirst%s", grade1, grade2);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR3;
		} else {
			q1grades[i] = atof(input);
		}
		ERR4: printf("%ssecond%s", grade1, grade2);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR4;
		} else {
			q2grades[i] = atof(input);
		}
	}
	for(int i = 0; i < periods; i++){
		for(int j = 0; j < 11; j++){
			percentages[i][j] = roundCalc(percentagesRaw[j], rounding[i]);
			results[i][j] = finalCalc(q1grades[i], q2grades[i], q1weights[i], q2weights[i], fweights[i], percentages[i][j]);
		}
	}
	for(int i = 0; i < periods; i++){
		
		char *guaranteed1 = "You are guaranteed to get at least an ";
		char *guaranteed2 = "You are guaranteed to get at least a ";
		char *guaranteed3 = " for the semester!";

		char *out1 = "You need at least a ";
		char *out2 = " to get a ";
		char *out3 = " for this semester.";
		
		int k = i + 1;

		for(int j = 0; j < 11; j++){
			if(results[i][j] <= 0){
				if(j <= 1){
					printf("Period %d: %s%c%c%s\n",k,guaranteed1,grades[j],symbol[j],guaranteed3);
				}
				if(j > 1){
					printf("Period %d: %s%c%c%s\n",k,guaranteed2,grades[j],symbol[j],guaranteed3);
				}
				j = 11;
			} else {
				printf("Period %d: %s%.2f%%%s%c%c%s\n",k,out1,results[i][j],out2,grades[j],symbol[j],out3);
			}
		}
	}
	return 0;
}
