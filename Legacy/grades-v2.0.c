#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char y[5];
	char n[5];
	char w[5];
	char r[5];
	char r5[5];
	char r8[5];
	char *guar1a = malloc(30); 
	strcpy(guar1a, "You are guaranteed to get an ");
	char *guar1b = malloc(29);
	strcpy(guar1b, "You are guaranteed to get a ");
	char *guar2a = malloc(20);
	strcpy(guar2a, " for the semester!\n");
	char *need1a = malloc(21);
	strcpy(need1a, "You need at least a ");
	char *need2a = malloc(11);
	strcpy(need2a, " to get a ");
	char *need2b = malloc(12);
	strcpy(need2b, " to get an ");
	char *whatis = malloc(28);
	strcpy(whatis, "What is your grade for the ");
	char *semest = malloc(28);
	strcpy(semest, " quarter of this semester? ");
	char *weight = malloc(27);
	strcpy(weight, "What is the weight of the ");
	char *please = malloc(24);
	strcpy(please, "Please enter a capital ");
	
	int whatiss = sizeof(whatis);
	int semests = sizeof(semest);
	int weights = sizeof(weight);
	int pleases = sizeof(please);
	printf("%d %d %d %d\n",whatiss,semests,weights,pleases);

	float ar = 94;
	float a_r = 90;
	float Br = 87;
	float br = 83;
	float b_r = 80;
	float Cr = 77;
	float cr = 73;
	float c_r = 70;
	float Dr = 67;
	float dr = 63;
	float d_r = 60;
	float a;
	float a_;
	float B;
	float b;
	float b_;
	float C;
	float c;
	float c_;
	float D;
	float d;
	float d_;

	float rf;

	float fa;
	float fa_;
	float fB;
	float fb;
	float fb_;
	float fC;
	float fc;
	float fc_;
	float fD;
	float fd;
	float fd_;
	
	float q1wr;
	float q2wr;
	float fwr;
	float fw;
	float q1gr;
	float q2gr;
	float q12w;
	printf("%sY: ",please);
	fgets(y,5,stdin);
	printf("%sN: ",please);
	fgets(n,5,stdin);
	printf("Does your teacher weigh the final separately from the quarters? ");
	fgets(w,5,stdin);
	if(strcmp(w, n) == 0){
		goto error;
	}
	printf("Does your teacher round? ");
	fgets(r,5,stdin);
	if(strcmp(r, n) == 0){
		rf = 0;
		goto round;
	}

	printf("Does your teacher round at 0.5? ");
	fgets(r5,5,stdin);
	if(strcmp(r5, y) == 0){
		rf = 0.5;
		goto round;
	}
	printf("Does your teacher round at 0.8? ");
	fgets(r8,5,stdin);
	if(strcmp(r8, y) == 0){
		rf = 0.2;
		goto round;
	}
round:
	a = ar - rf;
	a_ = a_r - rf;
	B = Br - rf;
	b = br - rf;
	b_ = b_r - rf;
	C = Cr - rf;
	c = cr - rf;
	c_ = c_r - rf;
	D = Dr - rf;
	d = dr - rf;
	d_ = d_r - rf;
input_grades_and_weights:
	printf("%sfirst%s",whatis,semest);
	scanf("%f", &q1gr);
	printf("%ssecond%s",whatis,semest);
	scanf("%f", &q2gr);
	printf("%sfirst%s",weight,semest);
	scanf("%f", &q1wr);
	printf("%ssecond%s",weight,semest);
	scanf("%f", &q2wr);
	printf("%sfinal? ",weight);
	scanf("%f", &fwr);
calc:
	fw = fwr / 100;
	q12w = (q1gr * (q1wr / 100)) + (q2gr * (q2wr / 100));

	fa = (a - q12w) / fw;
	fa_ = (a_ - q12w) / fw;
	fB = (B - q12w) / fw;
	fb = (b - q12w) / fw;
	fb_ = (b_ - q12w) / fw;
	fC = (C - q12w) / fw;
	fc = (c - q12w) / fw;
	fc_ = (c_ - q12w) / fw;
	fD = (D - q12w) / fw;
	fd = (d - q12w) / fw;
	fd_ = (d_ - q12w) / fw;
out:
	printf("Here are the results:\n");
	if(fa <= 0){
		printf("%sA%s\n", guar1a, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sA\n",need1a,fa,need2b);
	}
	if(fa_ <= 0){
		printf("%sA-%s\n", guar1a, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sA-\n",need1a,fa_,need2b);
	}
	if(fB <= 0){
		printf("%sB+%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sB+\n",need1a,fB,need2a);
	}
	if(fb <= 0){
		printf("%sB%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sB\n",need1a,fb,need2a);
	}
	if(fb_ <= 0){
		printf("%sB-%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sB-\n",need1a,fb_,need2a);
	}
	if(fC <= 0){
		printf("%sC+%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sC+\n",need1a,fC,need2a);
	}
	if(fc <= 0){
		printf("%sC%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sC\n",need1a,fc,need2a);
	}
	if(fc_ <= 0){
		printf("%sC-%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sC-\n",need1a,fc_,need2a);
	}
	if(fD <= 0){
		printf("%sD+%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sD+\n",need1a,fD,need2a);
	}
	if(fd <= 0){
		printf("%sD%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sD\n",need1a,fd,need2a);
	}
	if(fd_ <= 0){
		printf("%sD-%s\n", guar1b, guar2a);
		goto end;
	} else {
		printf("%s%.2f%sD-\n",need1a,fd_,need2a);
	}
	goto end;
error:
	printf("This function is not yet supported.\n");
end:
return 0;
}