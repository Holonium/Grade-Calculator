//This version implements multiple files in order to reduce size, as well as a custom header. Capabilities will be similar to those of v7. This is the main file.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int main(void){
	int i;
	int j;

	int v;
	
	char *guaranteed1 = "You are guaranteed to get at least an ";
	char *guaranteed2 = "You are guaranteed to get at least a ";
	char *guaranteed3 = " for the semester!";
	char *grade1 = "What is your grade for the ";
	char *grade2 = " quarter of this semester? ";
	char *out1 = "You need at least a ";
	char *out2 = "%% to get a ";
	char *out3 = " for this semester.";
	char *welcome = "Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class.";
	char *teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\nPlease enter the number of the teacher: ";
	
	range = 8;	
	
	for(i = 0; i < 6; i++){
		printf("%s", teacher_list);
		scanf("%d", &teachers[i]);
	
		v = validateTeacher(teachers, range);

		if(v == 0){
			printf("You have entered an invalid number!/n");
			i--;
		}
	}		
		//Put teachers in teachers.c...
	for(i = 0; i < 6; i++){
		if(teachers[i] == 1){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			/*q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;*/
			quarterWeight[i][1] = 0.45;
			quarterWeight[i][2] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 2){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		}
	}
	for(i = 0; i < 6; i++){
		printf("%sfirst%s", grade1, grade2);
		scanf("%lf", &quarterGrades[i][1]);
		printf("%ssecond%s", grade1, grade2);
		scanf("%lf", &quarterGrades[i][2]);
		//q12grade[i] = (q1grades[i] * q1weight[i]) + (q2grades[i] * q2weight[i]);
		Percents = roundPercents(roundingFactor, percentagesRaw);
		//Calculate necessary grades.
		Grades = determineFinals(quarterGrades, quarterWeight, finalWeight);
		/*for(j = 0; j < 11; j++){
			finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
		}*/
	}
