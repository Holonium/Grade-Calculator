//This version will implement support for six classes at once, as well as full usage of malloc for strings.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
//Declaration of counters and constants.
	int i;
	int j;
	int k;
	double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
//Declaration of constant characters.
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
//Declaration of strings.
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
//Declaration of arrays.
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
//Get inputs.
	for(i = 0; i < 6; i++){
		printf("%s", teacher_list);
		scanf("%d", &teachers[i]);
		//Baker
		if(teachers[i] == 1){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 2){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 3){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 45;
			q2weight[i] = 45;
			finalWeight[i] = 10;
		} else if(teachers[i] == 4){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 5){
			roundingFactor[i] = 0.2;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 6){
			roundingFactor[i] = 0.5;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		} else if(teachers[i] == 7){
			roundingFactor[i] = 0;
			for(j = 0; j < 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		} else if(teachers[i] == 8){
			roundingFactor[i] = 0;
			for(j = 0; j < 11; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		}
		printf("%sfirst%s", grade1, grade2);
		scanf("%lf", &q1grades[i]);
		printf("%ssecond%s", grade1, grade2);
		scanf("%lf", &q2grades[i]);
		q12grade[i] = (q1grades[i] * q1weight[i]) + (q2grades[i] * q2weight[i]);
		//Calculate necessary grades.
		for(j = 0; j < 11; j++){
			finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
		}
	}
	//output grades.
	for(i = 0; i < 6; i++){
		k = i + 1;
		for(j = 0; j < 11; j++){
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
end:
	return 0;
}
