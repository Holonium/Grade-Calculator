//This version implements multiple files, support for up to 8 classes, more teachers, a custom header, and an updated style.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(){
	double version = 8.01;
	int periods;
	double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

	char input[10];
	
	int isValid;

	printf("Welcome to v%.2f of the grade calculator.\n",version);
	ERR1: printf("Please enter the number of periods that you wish to calculate grades for (1-8):");
	//scanf("%d", &periods);
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
		char *teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\nPlease enter the number of the teacher for period ";
		int period = i + 1;
		ERR2: printf("%s%i: ",teacher_list,period);
		//scanf("%d", &teachers[i]);
		fgets(input, 10, stdin);
		isValid = verify_teacher(input);
		if(isValid != 0){
			printf("Enter a valid teacher! ");
			goto ERR2;
		} else {
			teachers[i] = atoi(input);
			//printf("%s %d\n",input,teachers[i]); Valid
		}
		int temp = teachers[i];
		//printf("teacher: %d\n", temp); Valid
		double tempweight;
		//tempweight = malloc(sizeof(double));
		//q1weights[i] = q1weight_select(temp, &tempweight);
		q1weight_select(temp, tempweight);
		q1weights[i] = *temp2;
		printf("Returned: %f, Transferred: %f\n", *temp2, tempweight); //Invalid, Transferred value is incorrect.
		q1weights[i] = tempweight;
		//q2weights[i] = q2weight_select(temp);
		q2weight_select(temp, tempweight);
		tempweight = *temp2;
		q2weights[i] = tempweight;
		//fweights[i] = fweight_select(temp);
		fweight_select(temp, tempweight);
		tempweight = *temp2;
		fweights[i] = tempweight;
		double tempround;
		//rounding[i] = rounding_select(temp);
		rounding_select(temp, tempround);
		tempround = *temp2;
		rounding[i] = tempround;
		printf("q1weights: %d q2weights: %d fweights: %d rounding: %d\n", q1weights[i], q2weights[i], fweights[i], rounding[i]); //All values invalid
		
		char *grade1 = "What is your grade for the ";
		char *grade2 = " quarter of this semester? ";
		
		ERR3: printf("%sfirst%s", grade1, grade2);
		//scanf("%lf", &q1grades[i]);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR3;
		} else {
			q1grades[i] = atof(input);
		}
		printf("q1grades: %d\n", q1grades[i]);
		ERR4: printf("%ssecond%s", grade1, grade2);
		//scanf("%lf", &q2grades[i]);
		fgets(input, 10, stdin);
		isValid = verify_grades(input);
		if(isValid != 0){
			printf("Enter a valid grade! ");
			goto ERR4;
		} else {
			q2grades[i] = atof(input);
		}
		printf("q2grades: %d\n", q2grades[i]);
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
		char *out2 = "%% to get a ";
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
				printf("Period %d: %s%.2f%s%c%c%s\n",k,out1,results[i][j],out2,grades[j],symbol[j],out3);
			}
		}
	}
	return 0;
}
