#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

double q1weight_select(int teacher){
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		return 0.45;
	} else if(teacher == 2 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		return 0.4;
	} else if(teacher == 11 || teacher == 5){
		return 0;
	}
	return 1;
}

double q2weight_select(int teacher){
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		return 0.45;
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		return 0.4;
	} else if(teacher == 11){
		return 1;
	}
	return 1;
}

double fweight_select(int teacher){
	if(teacher == 1 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		return 0.1;
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		return 0.2;
	} else if(teacher == 11){
		return 0;
	} else if(teacher == 3){
		return 0.05;
	}
	return 1;
}

double rounding_select(int teacher){
	if(teacher == 1 || teacher == 2 || teacher == 7 || teacher == 8 || teacher == 11 || teacher == 13){
		return 0;
	} else if(teacher == 5 || teacher == 12){
		return 0.2;
	} else if(teacher == 3 || teacher == 4 || teacher == 6 || teacher == 9 || teacher == 10){
		return 0.5;
	}
	return 1;
}
