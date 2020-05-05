#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"
#include "functions.h"

const char *version = "v1.0.0";
const double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
const char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
const char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
const char *teacher_list = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\n14) Other\nPlease enter the number of the teacher for period ";
const char *class_types = "1) Standard\n2) Honors\n3) AP\nPlease enter the number of the class type for period ";

const char *grade1 = "Please enter your grade for the ";
const char *grade2 = " quarter of this semester: ";

const char *guaranteed1 = "You are guaranteed to get at least an ";
const char *guaranteed2 = "You are guaranteed to get at least a ";
const char *guaranteed3 = " for the semester!";

const char *out1 = "You need at least a ";
const char *out2 = " to get a ";
const char *out3 = " for this semester.";


int main(){
	printf("Welcome to %s of the grade calculator.\n", version);
	//printf("WARNING: THIS IS AN ALPHA RELEASE, STABILITY IS NOT ENSURED!\n");
	
	char *GPA = malloc(2 * sizeof(char));
	memset(GPA, '\0', 2);
	double totalCredits = 0;
	double totalGradePointsWeighted = 0;
	double totalGradePointsUnweighted = 0;

	while(verify_YN(GPA) == 0){
		printf("Do you wish to calculate your GPA? (Y/N) ");
		scanf(" %c", GPA);
		if(verify_YN(GPA) != 0){
			break;
		}
		printf("Invalid input! ");
	}
	if(verify_YN(GPA) == 1){
		int years = 0;
		while(verify_years(years) != 0){
			printf("Please enter the number of years that you have completed (1-3): ");
			scanf(" %d", &years);
			if(verify_years(years) == 0){
				break;
			}
			printf("Enter a valid number of years! ");
		}
		for(int i = 0; i < years; i++){
			int year = i + 1;
			for(int j = 1; j < 3; j++){
				int periods = 0;
				while(verify_periods(periods) != 0){
					printf("Please enter the number of periods for semester %i of year %i (1-8): ", j, year);
					scanf(" %d", &periods);
					if(verify_periods(periods) == 0){
						break;
					}
					printf("Enter a valid number of periods! ");
				}
				for(int k = 0; k < periods; k++){
					double grade = -1;
					int type = 0;
					double credits = 0;
					double roundingTemp = 2;
					int period = k + 1;
					while(verify_grade(grade) != 0){
						printf("Please enter your grade for period %i of semester %i of year %i: ", period, j, year);
						scanf(" %lf", &grade);
						if(verify_grade(grade) == 0){
							break;
						}
						printf("Enter a valid grade! ");
					}
					while(verify_type(type) != 0){
						printf("%s%i of semester %i of year %i (1-3): ", class_types, period, j, year);
						scanf(" %d", &type);
						if(verify_type(type) == 0){
							break;
						}
						printf("Enter a valid type! ");
					}
					while(verify_credits(credits) != 0){
						printf("Please enter the number of credits for period %i of semester %i of year %i: ", period, j, year);
						scanf(" %lf", &credits);
						if(verify_credits(credits) == 0){
							break;
						}
						printf("Enter a valid number of credits! ");
					}
					while(verify_rounding(roundingTemp) != 0){
						printf("Please enter the point at which the teacher rounds: ");
						scanf(" %lf", &roundingTemp);
						if(verify_rounding(roundingTemp) == 0){
							break;
						}
						printf("Enter a valid rounding point! ");
					}
					double rounding;
					if(roundingTemp == 0){
						rounding = 1;
					} else {
						rounding = 1 - roundingTemp;
					}
					totalGradePointsUnweighted += gpa_class(grade, credits, rounding, 1);
					totalGradePointsWeighted += gpa_class(grade, credits, rounding, type);
					totalCredits += credits;
				}
			}
		}
		double currentGPAWeight = gpa_full(totalGradePointsWeighted, totalCredits);
		double currentGPAUnweight = gpa_full(totalGradePointsUnweighted, totalCredits);
		printf("Your current weighted GPA is: %.3f\nYour current unweighted GPA is: %.3f\n", currentGPAWeight, currentGPAUnweight);
	}
	char *sem = malloc(2 * sizeof(char));
	memset(sem, '\0', 2);
	while(verify_YN(sem) == 0){
		printf("Are you currently in semester 2 of the year? (Y/N) ");
		scanf(" %c", sem);
		if(verify_YN(sem) != 0){
			break;
		}
		printf("Invalid input! ");
	}
	if(verify_YN(sem) == 1){
		int periods = 0;
		while(verify_periods(periods) != 0){
			printf("Please enter the number of periods for semester 1 of the current year (1-8): ");
			scanf(" %d", &periods);
			if(verify_periods(periods) == 0){
				break;
			}
			printf("Enter a valid number of periods! ");
		}
		for(int i = 0; i < periods; i++){
			double grade = -1;
			int type = 0;
			double credits = 0;
			double roundingTemp = 2;
			int period = i + 1;
			while(verify_grade(grade) != 0){
				printf("Please enter the graded for period %i of semester 1 of the current year: ", period);
				scanf(" %lf", &grade);
				if(verify_grade(grade) == 0){
					break;
				}
				printf("Enter a valid grade! ");
			}
			while(verify_type(type) != 0){
				printf("%s%i of semester 1 of the current year (1-3): ", class_types, period);
				scanf(" %d", &type);
				if(verify_type(type) == 0){
					break;
				}
				printf("Enter a valid type! ");
			}
			while(verify_credits(credits) != 0){
				printf("Please enter the number of credits for period %i of semester 1 of the current year: ", period);
				scanf(" %lf", &credits);
				if(verify_credits(credits) == 0){
					break;
				}
				printf("Enter a valid number of credits! ");
			}
			while(verify_rounding(roundingTemp) != 0){
				printf("Please enter the point at which the teacher rounds: ");
				scanf(" %lf", &roundingTemp);
				if(verify_rounding(roundingTemp) == 0){
					break;
				}
				printf("Enter a valid rounding point! ");
			}
			double rounding;
			if(roundingTemp == 0){
				rounding = 0;
			} else {
				rounding = 1 - roundingTemp;
			}
			totalGradePointsUnweighted += gpa_class(grade, credits, rounding, 1);
			totalGradePointsWeighted += gpa_class(grade, credits, rounding, type);
			totalCredits += credits;
		}
	}
	int periods = 0;
	while(verify_periods(periods) != 0){
		printf("Please enter the number of periods for the current semester (1-8): ");
		scanf(" %d", &periods);
		if(verify_periods(periods) == 0){
			break;
		}
		printf("Enter a valid number of periods! ");
	}
	int teachers[8] = { 0 };
	double rounding[8] = { 0 };
	double q1weight[8] = { 0 };
	double q1grades[8] = { 0 };
	double q2weight[8] = { 0 };
	double q2grades[8] = { 0 };
	double f1weight[8] = { 0 };
	double f2weight[8] = { 0 };
	double f2grades[8] = { 0 };
	double credits[8] = { 0 };
	int types[8] = { 0 };
	double percentages[8][11];
	double finalGrades[8][11];
	char *finals = malloc(2 * sizeof(char));
	memset(finals, '\0', 2);
	for(int i = 0; i < periods; i++){
		int period = i + 1;
		while(verify_teacher(teachers[i]) != 0){
			printf("%s%i: ",teacher_list,period);
			scanf(" %d", &teachers[i]);
			if(verify_teacher(teachers[i]) == 0){
				break;
			}
			printf("Enter a valid teacher! ");
		}
		if(teachers[i] == 14){
			while(verify_weight(q1weight[i]) != 0){
				printf("Please enter the weight of the first quarter as a decimal: ");
				scanf(" %lf", &q1weight[i]);
				if(verify_weight(q1weight[i]) == 0){
					break;
				}
				printf("Enter a valid weight! ");
			}
			while(verify_weight(q2weight[i]) != 0){
				printf("Please enter the weight of the second quarter as a decimal: ");
				scanf(" %lf", &q2weight[i]);
				if(verify_weight(q2weight[i]) == 0){
					break;
				}
				printf("Enter a valid weight! ");
			}
			while(verify_weight(f1weight[i]) != 0){
				printf("Please enter the weight of the final as a decimal: ");
				scanf(" %lf", &f1weight[i]);
				if(verify_weight(f1weight[i]) == 0){
					break;
				}
				printf("Enter a valid weight! ");
			}
			double roundingTemp;
			while(verify_rounding(roundingTemp) != 0){
				printf("Please enter the point at which the teacher rounds: ");
				scanf(" %lf", &roundingTemp);
				if(verify_rounding(roundingTemp) == 0){
					if(roundingTemp == 0){
						rounding[i] = 0;
					} else {
						rounding[i] = 1 - roundingTemp;
					}
					break;
				}
				printf("Enter a valid rounding point! ");
			}
		} else {
			q1weight[i] = q1weight_select(teachers[i]);
			q2weight[i] = q2weight_select(teachers[i]);
			f1weight[i] = fweight_select(teachers[i]);
			rounding[i] = rounding_select(teachers[i]);
			if(teachers[i] == 3){
				f2weight[i] = fweight_select(teachers[i]);
			}
		}
		while(verify_grade(q1grades[i]) != 0){
			printf("Please enter your grade for the first quarter of period %i: ", period);
			scanf(" %lf", &q1grades[i]);
			if(verify_grade(q1grades[i]) == 0){
				break;
			}
			printf("Enter a valid grade! ");
		}
		while(verify_grade(q2grades[i]) != 0){
			printf("Please enter your grade for the second quarter of period %i: ", period);
			scanf(" %lf", &q2grades[i]);
			if(verify_grade(q2grades[i]) == 0){
				break;
			}
			printf("Enter a valid grade! ");
		}
		if(teachers[i] == 3){
			while(verify_grade(f2grades[i]) != 0){
				printf("Please enter your grade for the first part of the final: ");
				scanf(" %lf", &f2grades[i]);
				if(verify_grade(f2grades[i]) == 0){
					break;
				}
				printf("Enter a valid grade! ");
			}
		}
		while(verify_credits(credits[i]) != 0){
			printf("Please enter the number of credits this class is worth: ");
			scanf(" %lf", &credits[i]);
			if(verify_credits(credits[i]) == 0){
				break;
			}
			printf("Enter a valid number of credits! ");
		}
		while(verify_type(types[i]) != 0){
			printf("%s%i of this year (1-3): ", class_types, period);
			scanf(" %d", &types[i]);
			if(verify_type(types[i]) == 0){
				break;
			}
			printf("Enter a valid type! ");
		}
		for(int j = 0; j < 11; j++){
			percentages[i][j] = round_calc(percentagesRaw[j], rounding[i]);
			if(teachers[i] == 3){
				finalGrades[i][j] = final_calc_multiweight(q1grades[i], q2grades[i], f2grades[i], q1weight[i], q2weight[i], f2weight[i], f1weight[i], percentages[i][j]);
			} else {
				finalGrades[i][j] = final_calc(q1grades[i], q2grades[i], q1weight[i], q2weight[i], f1weight[i], percentages[i][j]);
			}
		}
	}
	for(int i = 0; i < periods; i++){
		int period = i + 1;
		for(int j = 0; j < 11; j++){
			if(finalGrades[i][j] <= 0){
				if(j <= 1){
					printf("Period %d: %s%c%c%s\n",period,guaranteed1,grades[j],symbol[j],guaranteed3);
				}
				if(j > 1){
					printf("Period %d: %s%c%c%s\n",period,guaranteed2,grades[j],symbol[j],guaranteed3);
				}
				totalGradePointsUnweighted += gpa_class(finalGrades[i][j], credits[i], rounding[i], 1);
				totalGradePointsWeighted += gpa_class(finalGrades[i][j], credits[i], rounding[i], types[i]);
				totalCredits += credits[i];
				j = 11;
			} else {
				printf("Period %d: %s%.2f%%%s%c%c%s\n",period,out1,finalGrades[i][j],out2,grades[j],symbol[j],out3);
			}
		}
	}
	double GPAWeight = gpa_full(totalGradePointsWeighted, totalCredits);
	double GPAUnweight = gpa_full(totalGradePointsUnweighted, totalCredits);
	printf("Your minimum weighted GPA is: %.3f\nYour minimum unweighted GPA is: %.3f\n", GPAWeight, GPAUnweight);

	free(GPA);
	free(sem);

	return 0;
}
