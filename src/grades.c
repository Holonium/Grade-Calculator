#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "functions.h"

extern const char version[] = "v1.0.0a1";
extern const double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
extern const char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
extern const char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
extern const double gpa = 4.00;
extern const char *teacher_list_charter = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\n14) Other\nPlease enter the number of the teacher for period ";
extern const char *class_types = "1) Standard\n2) Honors\n3) AP\nPlease enter the number of the class type for period ";

extern const char *grade1 = "Please enter your grade for the ";
extern const char *grade2 = " quarter of this semester: ";

extern const char *guaranteed1 = "You are guaranteed to get at least an ";
extern const char *guaranteed2 = "You are guaranteed to get at least a ";
extern const char *guaranteed3 = " for the semester!";

extern const char *out1 = "You need at least a ";
extern const char *out2 = " to get a ";
extern const char *out3 = " for this semester.";


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
