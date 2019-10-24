#include <stdio.h>
#include <string.h>

int main(void){
	char y[5];
	char n[5];

	char w[5];
	char r[5];
	char five[5];
	char eight[5];

	char guar1an[] = "You are guaranteed to get at least an ";
	char guar1a[] = "You are guaranteed to get at least a ";
	char guar2[] = " for the semester!";

	char grade1[] = "What is your grade for the ";
	char grade2[] = " quarter of this semester? ";
	char need1[] = "You need at least a ";
	char need2[] = " to get a ";
	char need3[] = " for this semester";

	char weight[] = "What is the weight of the ";
	char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
	char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};

	double lettersRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
	double letters[10];

	double roundingFactor;

	double finals[10];

	double q1Grade;
	double q2Grade;
	double q1WeightRaw;
	double q2WeightRaw;
	double finalWeightRaw;
	double q12Grade;

	int i;

	printf("Welcome to the grading calculator. Please answer the following with a Y for Yes, or an N for No.\n");
	printf("Please enter a capital Y: ");
	fgets(y,5,stdin);
	printf("Please enter a capital N: ");
	fgets(n,5,stdin);	
	printf("Does your teacher weigh the final separately from the quarters? ");
	fgets(w,5,stdin);
	if(strcmp(w,n) == 0){
		goto error;
	}
	printf("Does your teacher round? ");
	fgets(r,5,stdin);

	if(strcmp(r,n) == 0){
		roundingFactor = 0;
		goto rounding;
	}
	printf("Does your teacher round at 0.5? ");
	fgets(five,5,stdin);
	if(strcmp(five,y) == 0){
		roundingFactor = 0.5;
		goto rounding;
	}
	printf("Does your teacher round at 0.8? ");
	fgets(eight,5,stdin);
	if(strcmp(eight,y) == 0){
		roundingFactor = 0.2;
		goto rounding;
	} else {
		goto error2;
	}
rounding:
	for(i = 0; i <= 10; i++){
		letters[i] = lettersRaw[i] - roundingFactor;
	}

	printf("%sfirst%s", grade1,grade2);
	scanf("%lf",&q1Grade);
	printf("%ssecond%s", grade1,grade2);
	scanf("%lf",&q2Grade);
	printf("%sfirst%s",weight,grade2);
	scanf("%lf",&q1WeightRaw);
	printf("%ssecond%s", weight,grade2);
	scanf("%lf",&q2WeightRaw);
	printf("%sfinal? ",weight);
	scanf("%lf",&finalWeightRaw);
	q12Grade = (q1Grade * (q1WeightRaw / 100)) + (q2Grade * (q2WeightRaw / 100));
calculations:
	for(i = 0; i <= 10; i++){
		finals[i] = (letters[i] - q12Grade) / (finalWeightRaw / 100);
	}
output:
	for(i = 0; i <= 10; i++){
		if(finals[i] <= 0){
			if(i <= 1){
				printf("%s%c%c%s\n",guar1an,grades[i],symbol[i],guar2);
			}
			if(i > 1){
				printf("%s%c%c%s\n",guar1a,grades[i],symbol[i],guar2);
			}
			i = 10;
		} else {
			printf("%s%.2f%s%c%c%s\n",need1,finals[i],need2,grades[i],symbol[i],need3);
		}
	}
	goto end;
error:
	printf("This feature is not yet supported.\n");
	goto end;
error2:
	printf("Invalid response!\n");
	goto end;
end:
return 0;
}
