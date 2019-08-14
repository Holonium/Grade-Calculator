//This version implements multiple files in order to reduce size, as well as a custom header. Capabilities will be similar to those of v7. This is the main file.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int main(void){
	int i;
	int j;

	int v;
	
	int range = 8;

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
	
	//int *percentRaw = malloc(11 * sizeof(double));
	for(i = 0; i < 11; i++){
		double percentagesRaw[11] = {93,90,87,83,80,77,73,70,67,63,60};
		percentRaw[i] = percentagesRaw[i];
	}
	int *quartergrades = malloc(12 * sizeof(double));
	int *percentages = malloc(66 * sizeof(double));
	int *quarterWeight = malloc(12 * sizeof(double));
	int *finalWeight = malloc(6 * sizeof(double));
	int *roundingFactor = malloc(6 * sizeof(double));
	int *finals = malloc(66 * sizeof(double));
	int *q12grades = malloc(6 * sizeof(double));
	int *teachers =  malloc(6 * sizeof(int));

	typedef double grades[6][11];
	typedef double qgrades[6][2];
	typedef double 11element[11];
	typedef double 6double[6];
	typedef int 6int[6];

	double percentRaw[11];
	11element *perRaw;

	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};


