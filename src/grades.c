#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "functions.h"

int main(){
	printf("Welcome to %s of the grade calculator.\n", version);
	printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	
	char input[10];
	char GPA[2];
	double totalCredits;
	double totalGradePointsWeighted;
	
	while(verify_YN(GPA != 0)){
		printf("Do you wish to calculate your GPA? (Y/N) ");
		scanf("%c", GPA);
		printf("Invalid input! ");
	}
	if(GPA == "Y"){
		int years;
		while(verify_year(years) != 0){
			printf("Please enter the number of years that you have completed (1-3): ");
			scanf("%i", years);
			printf("Enter a valid number of years! ");
		}
		for(int i = 0; i < years; i++){
			int periods;
			while(verify_classes(periods) != 0){
				printf("Please enter the number of periods for year %i (1-8): ", i + 1);
				scanf("%i", periods);
				printf("Enter a valid number of periods! ");
			}
			for(int j = 0; j < periods; j++){
				char tempLetter[3];
				while(verify_letter(tempLetter[0]) != 0){
					printf("Please enter the letter grade for period %i: ");
