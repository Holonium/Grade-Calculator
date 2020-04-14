#include <stdio.h>
#include "functions.h"

void q1weight_select(int teacher){
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		double temp = 0.45;
		q1temp = &temp;
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		double temp = 0.4;
		q1temp = &temp;
	} else if(teacher == 11){
		double temp = 0;
		q1temp = &temp;
	}	
}

void q2weight_select(int teacher){
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		double temp = 0.45;
		q2temp = &temp;
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		double temp = 0.4;
		q2temp = &temp;
	} else if(teacher == 11){
		double temp = 1;
		q2temp = &temp;
	}
}

void fweight_select(int teacher){
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		double temp = 0.1;
		fwtemp = &temp;
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		double temp = 0.2;
		fwtemp = &temp;
	} else if(teacher == 11){
		double temp = 0;
		fwtemp = &temp;
	}
}

void rounding_select(int teacher){
	if(teacher == 1 || teacher == 2 || teacher == 7 || teacher == 8 || teacher == 11 || teacher == 13){
		double temp = 0;
		roundtemp = &temp;
	} else if(teacher == 5 || teacher == 12){
		double temp = 0.2;
		roundtemp = &temp;
	} else if(teacher == 3 || teacher == 4 || teacher == 6 || teacher == 9 || teacher == 10){
		double temp = 0.5;
		roundtemp = &temp;
	}
}
