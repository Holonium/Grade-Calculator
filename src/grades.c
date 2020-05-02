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
	double totalGradePointsUnweighted;
	
	while(verify_YN(GPA != 0)){
		printf("Do you wish to calculate your GPA? (Y/N) ");
		scanf("%c", GPA);
		printf("Invalid input! ");
	}
	if(GPA == "Y"){
		int years;
		while(verify_years(years) != 0){
			printf("Please enter the number of years that you have completed (1-3): ");
			scanf("%i", years);
			printf("Enter a valid number of years! ");
		}
		for(int i = 0; i < years; i++){
			int year = years + 1;
			for(int j = 1; j < 3; j++){
				int periods;
				while(verify_periods(periods) != 0){
					printf("Please enter the number of periods for semester %i of year %i (1-8): ", j, year);
					scanf("%i", periods);
					printf("Enter a valid number of periods! ");
				}
				for(int k = 0; k < periods; k++){
					double grade;
					int type;
					double credits;
					double roundingTemp;
					int period = k + 1;
					while(verify_grade(grade) != 0){
						printf("Please enter your grade for period %i of semester %i of year %i: ", period, j, year);
						scanf("%f", grade);
						printf("Enter a valid grade! ");
					}
					while(verify_type(type) != 0){
						printf("%s%i of semester %i of year %i (1-3): ", class_types, period, j, year);
						scanf("%i", type);
						printf("Enter a valid type! ");
					}
					while(verify_credits(credits) != 0){
						printf("Please enter the number of credits for period %i of semester %i of year %i: ", period, j, year);
						scanf("%f", credits);
						printf("Enter a valid number of credits! ");
					}
					while(verify_rounding(roundingTemp) != 0){
						printf("Please enter the point at which the teacher rounds: ");
						scanf("%f", roundingTemp);
						printf("Enter a valid rounding point! ");
					}
					double rounding = 1 - roundingTemp;
					totalGradePointsUnweighted += gpa_class(grade, credits, rounding, 1);
					totalGradePointsWeighted += gpa_class(grade, credits, rounding, type);
					totalCredits += credits;
				}
			}
		}
	}
	
	return 0;
}
