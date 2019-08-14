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
//Declaration of strings with malloc.
	char *guaranteed1;
	char *guaranteed2;
	char *guaranteed3;
	char *grade1;
	char *grade2;
	char *out1;
	char *out2;
	char *out3;
	char *welcome;
	char *teacher_list;
//Assignment of string values.
	guaranteed1 = malloc(39);
	guaranteed2 = malloc(38);
	guaranteed3 = malloc(19);
	grade1 = malloc(28);
	grade2 = malloc(28);
	out1 = malloc(21);
	out2 = malloc(11);
	out3 = malloc(19);
	welcome = malloc(162);
	teacher_list = malloc(165);
//String copy.
	strcpy(guaranteed1,"You are guaranteed to get at least an ");
	strcpy(guaranteed2,"You are guaranteed to get at least a ");
	strcpy(guaranteed3," for the semester!");
	strcpy(grade1,"What is your grade for the ");
	strcpy(grade2," quarter of this semester? ");
	strcpy(out1,"You need at least a ");
	strcpy(out2," to get a ");
	strcpy(out3," for this semester");
	strcpy(welcome,"Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class. Use Y for yes and N for no.");
	strcpy(teacher_list,"1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\nPlease enter the number of the teacher: ");
//Declaration of grade and rounding arrays.
	double teachers[5];
	double q1grades[5];
	double q2grades[5];
	double q1weight[5];
	double q2weight[5];
	double q12grade[5];
	double finalWeight[5];
	double roundingFactor[5];
	double percentages[5][10];
	double finals[5][10];
//Get inputs.
	for(i = 0; i <= 5; i++){
		printf("%s", teacher_list);
		scanf("%d", &teachers[i]);
		//Baker
		if(teachers[i] == 1){
			roundingFactor[i] = 0;
			for(j = 0; j <= 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		}
		//Sabatke
		if(teachers[i] == 2){
			roundingFactor[i] = 0;
			for(j = 0; j <= 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		}
		//Bright
		if(teachers[i] == 3){
			roundingFactor[i] = 0.5;
			for(j = 0; j <= 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 45;
			q2weight[i] = 45;
			finalWeight[i] = 10;
		}
		//Ginorio
		if(teachers[i] == 4){
			roundingFactor[i] = 0.5;
			for(j = 0; j <= 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.45;
			q2weight[i] = 0.45;
			finalWeight[i] = 0.1;
		}
		//McCormack
		if(teachers[i] == 5){
			roundingFactor[i] = 0.2;
			for(j = 0; j <= 10; j++){
				percentages[i][j] = percentagesRaw[j] - roundingFactor[i];
			}
			q1weight[i] = 0.4;
			q2weight[i] = 0.4;
			finalWeight[i] = 0.2;
		}
		//Gabrielsen
		if(teachers[i] == 6){
			printf("Not yet supported, enter a random teacher and grades to continue...\n");
			goto end; 
		}
		printf("%sfirst%s", grade1, grade2);
		scanf("%f", &q1grades[i]);
		printf("%ssecond%s", grade1, grade2);
		scanf("%f", &q2grades[i]);
		q12grade[i] = (q1grades[i] * q1weight[i]) + (q2grades[i] * q2weight[i]);
		for(j = 0; j <= 10; j++){
			finals[i][j] = (percentages[i][j] - q12grade[i]) / (finalWeight[i]);
		}
	}
	for(i = 0; i <= 5; i++){
		k = i + 1;
		for(j = 0; j <= 10; j++);
		if(finals[i][j] <= 0){
			if(j <= 1){
				printf("Period %d: %s%c%c%s\n",k,guaranteed1,grades[j],symbol[j],guaranteed3);
			}
			if(j > 1){
				printf("Period %d: %s%c%c%s\n",k,guaranteed2,grades[j],symbol[j],guaranteed3);
			}
			j = 10;
		} else {
			printf("Period %d: %s%.2f%s%c%c%s\n",k,out1,finals[i][j],out2,grades[j],symbol[j],out3);
		}
	}
end:
	free(guaranteed1);
	free(guaranteed2);
	free(guaranteed3);
	free(grade1);
	free(grade2);
	free(out1);
	free(out2);
	free(out3);
	free(welcome);
	free(teacher_list);
	return 0;
}
