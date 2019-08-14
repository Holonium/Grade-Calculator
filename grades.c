#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

//Teacher functions, see teachers.c in final
//int validateInput(int input,int range);
//double detQuarterWeight1(int input);
//double detQuarterWeight2(int input);
//double detFinalWeight(int input);
//double detRoundingFactor(int input);

//Mathematical functions, see calc.c in final
//double round(double roundingFactor,double percentagesRaw);
//double weightQuarters(double quarterWeight1, double quarterWeight2, double quarterGrade1, double quarterGrade2);
//double detFinal(double weighted, double percentage, double finalWeight);

int main(void){
	//Declare constants and strings
	double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
	
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
	
	char *guaranteed1 = "You are guaranteed to get at least an ";
	char *guaranteed2 = "You are guaranteed to get at least a ";
	char *guaranteed3 = " for the semester!";
	char *grade1 = "What is your grade for the ";
	char *grade2 = " quarter of this semester? ";
	char *out1 = "You need at least a ";
	char *out2 = "%% to get a ";
	char *out3 = " for this semester.";
	char *welcome = "Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class.";
	char *teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\nPlease enter the number of the teacher: ";
	
	int range = 2;
	
	//Declare arrays
	int teachers[6];
	double q1grades[6];
	double q2grades[6];
	double q1weight[6];
	double q2weight[6];
	double q12grade[6];
	double finalWeight[6];
	double roundingFactor[6];
	double percentages[6][11];
	double finals[6][11];
	
	for(int i = 0; i < 6; i++){
		printf("%s", teacher_list);
		scanf("%d", &teachers[i]);
		int isValid = validateInput(teachers[i], range);
		if(isValid == 0){
			printf("Invalid input! Try again.");
			i--;
		}
	}
	for(int i = 0; i < 6; i++){
		roundingFactor[i] = detRoundingFactor(teachers[i]);
		q1weight[i] = detQuarterWeight1(teachers[i]);
		q2weight[i] = detQuarterWeight2(teachers[i]);
		finalWeight[i] = detFinalWeight(teachers[i]);
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 11; j++){
			percentages[i][j] = round(roundingFactor[i], percentagesRaw[j]);
		}
	}
	for(int i = 0; i < 6; i++){	
		printf("%sfirst%s", grade1, grade2);
		scanf("%lf", &q1grades[i]);
		printf("%ssecond%s", grade1, grade2);
		scanf("%lf", &q2grades[i]);
		
		q12grade[i] = weightQuarters(q1weight[i], q2weight[i], q1grades[i], q2grades[i]);
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 11; j++){
			finals[i][j] = detFinal(q12grade[i], percentages[i][j],finalWeight[i]);
		}
	}
	
		for(int i = 0; i < 6; i++){
			int k = i + 1;
			for(int j = 0; j < 11; j++){
			if(finals[i][j] <= 0){
				if(j <= 1){
					printf("Period %d: %s%c%c%s\n",k,guaranteed1,grades[j],symbol[j],guaranteed3);
				}
				if(j > 1){
					printf("Period %d: %s%c%c%s\n",k,guaranteed2,grades[j],symbol[j],guaranteed3);
				}
				j = 11;
			} else {
				printf("Period %d: %s%.2f%s%c%c%s\n",k,out1,finals[i][j],out2,grades[j],symbol[j],out3);
			}
		}
	}
	
	return 0;
}
int validateInput(int input,int range){
	int isValid=1;
	if(input <= 0 || input > range){
		isValid = 0;
	}
	return isValid;
}
double detQuarterWeight1(int input){
	double quarterWeight1 = 0;
	switch(input){
		case 1: quarterWeight1 = 0.45;
			break;
		case 2: quarterWeight1 = 0.4;
			break;
		default: printf("You have entered an invalid teacher\n");
	}
	return quarterWeight1;
}
double detQuarterWeight2(int input){
	double quarterWeight2 = 0;
	switch(input){
		case 1: quarterWeight2 = 0.45;
			break;
		case 2: quarterWeight2 = 0.4;
			break;
		default: printf("You have entered an invalid teacher\n");
	}
	return quarterWeight2;
}
double detFinalWeight(int input){
	double finalWeight = 0;
	switch(input){
		case 1: finalWeight = 0.1;
			break;
		case 2: finalWeight = 0.2;
			break;
		default: printf("You have entered an invalid teacher\n");
	}
	return finalWeight;
}
double detRoundingFactor(int input){
	double roundingFactor = 0;
	switch(input){
		case 1: roundingFactor = 0;
			break;
		case 2: roundingFactor = 0;
			break;
		default: printf("You have entered an invalid teacher\n");
	}
	return roundingFactor;
}
double round(double roundingFactor,double percentagesRaw){
	double percentage = percentagesRaw -roundingFactor;
	return percentage;
}
double weightQuarters(double quarterWeight1, double quarterWeight2, double quarterGrade1, double quarterGrade2){
	double weighted = (quarterWeight1 * quarterGrade1) + (quarterWeight2 * quarterGrade2);
	return weighted;
}
double detFinal(double weighted, double percentage, double finalWeight){
	//finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
	double finalGrade = (percentage - weighted) / finalWeight;
	return finalGrade;
}
