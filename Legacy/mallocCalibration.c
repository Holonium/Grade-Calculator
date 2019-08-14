#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char guar1an[] = "You are guaranteed to get at least an ";
	char guar1a[] = "You are guaranteed to get at least a ";
	char guar2[] = " for the semester!";

	char grade1[] = "What is your grade for the ";
	char grade2[] = " quarter of this semester? ";
	char need1[] = "You need at least a ";
	char need2[] = " to get a ";
	char need3[] = " for this semester";

	char welcome[] = "Welcome to the grade calculator! This calculator will tell you what you need on your final to get a certain letter grade for a class. Use Y for yes and N for no.";
	char teacher_list[] = "1) Mrs. Baker\n2) Mr. Sabatke\n4) Ms. Bright\n5) Mr. Ginorio\n6) Mr. McCormack\n7) Mr. Gabrielsen\n8)Mrs. Solsvik\nPlease enter the number of the teacher: ";
	
	int i;

	int length[9];
	
	length[0] = strlen(guar1an);
	length[1] = strlen(guar1a);
	length[2] = strlen(guar2);
	length[3] = strlen(grade1);
	length[4] = strlen(grade2);
	length[5] = strlen(need1);
	length[6] = strlen(need2);
	length[7] = strlen(need3);
	length[8] = strlen(welcome);
	length[9] = strlen(teacher_list);

	for(i = 0; i <= 9; i++){
		length[i] = length[i] + 1;
		printf("%d\n", length[i]);
	}
	printf("%s",teacher_list);
	return 0;
}
