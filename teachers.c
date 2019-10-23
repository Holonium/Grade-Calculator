//This file handles the return of teacher constants.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

void q1weight_select(int teacher, double weight){

	/*switch(teacher){
		case 1 : //Baker
			weight = 0.45;
			break;
		case 2 : //Sabatke
			weight = 0.4;
			break;
		case 3 : //Bright
			weight = 0.45;
			break;
		case 4 : //Ginorio
			weight = 0.45;
			break;
		case 5 : //McCormack
			weight = 0.4;
			break;
		case 6 : //Gabrielsen
			weight = 0.4;
			break;
		case 7 : //Harrison
			weight = 0.45;
			break;
		case 8 : //Williams
			weight = 0.45;
			break;
		case 9 : //Hall
			weight = 0.4;
			break;
		case 10 : //Vaughan
			weight = 0.4;
			break;
		case 11 : //Ketchum
			weight = 0;
			break;
		case 12 : //Solsvik
			weight = 0.4;
			break;
		case 13 : //Rigg
			weight = 0.45;
			break;
		default :
			weight = 7;
	}*/

	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		//return 0.45;
		double temp = 0.45;
		//weight = temp;
		temp2 = &temp;
		//printf("%d\n", temp);
		//printf("End if: %f\n", *temp2); Valid
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		//return 0.4;
		double temp = 0.4;
		temp2 = &temp;
	} else if(teacher == 11){
		//return 0;
		double temp = 0;
		temp2 = &temp;
	}	

	//printf("%d %d\n",teacher,weight);
	//return weight;
}

void q2weight_select(int teacher, double weight){

	/*switch(teacher){
		case 1 : //Baker
			weight = 0.1;
			break;
		case 2 : //Sabatke
			weight = 0.2;
			break;
		case 3 : //Bright
			weight = 0.1;
			break;
		case 4 : //Ginorio
			weight = 0.1;
			break;
		case 5 : //McCormack
			weight = 0.2;
			break;
		case 6 : //Gabrielsen
			weight = 0.2;
			break;
		case 7 : //Harrison
			weight = 0.1;
			break;
		case 8 : //Williams
			weight = 0.1;
			break;
		case 9 : //Hall
			weight = 0.2;
			break;
		case 10 : //Vaughan
			weight = 0.2;
			break;
		case 11 : //Ketchum
			weight = 0;
			break;
		case 12 : //Solsvik
			weight = 0.2;
			break;
		case 13 : //Rigg
			weight = 0.1;
			break;
		default :
			weight = 7;
	}*/
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		//return 0.45;
		double temp = 0.45;
		//weight = temp;
		temp2 = &temp;
		//printf("%d\n", temp);
		//printf("End if: %f\n", *temp2);
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		//return 0.4;
		double temp = 0.4;
		temp2 = &temp;
	} else if(teacher == 11){
		//return 0;
		double temp = 1;
		temp2 = &temp;
	}
	//printf("%d\n",weight);
	//return weight;
}

void fweight_select(int teacher, double weight){
	
	/*switch(teacher){
		case 1 : //Baker
			weight = 0.45;
			break;
		case 2 : //Sabatke
			weight = 0.4;
			break;
		case 3 : //Bright
			weight = 0.45;
			break;
		case 4 : //Ginorio
			weight = 0.45;
			break;
		case 5 : //McCormack
			weight = 0.4;
			break;
		case 6 : //Gabrielsen
			weight = 0.4;
			break;
		case 7 : //Harrison
			weight = 0.45;
			break;
		case 8 : //Williams
			weight = 0.45;
			break;
		case 9 : //Hall
			weight = 0.4;
			break;
		case 10 : //Vaughan
			weight = 0.4;
			break;
		case 11 : //Ketchum
			weight = 0;
			break;
		case 12 : //Solsvik
			weight = 0.4;
			break;
		case 13 : //Rigg
			weight = 0.45;
			break;
		default :
			weight = 7;
	}*/
	if(teacher == 1 || teacher == 3 || teacher == 4 || teacher == 7 || teacher == 8 || teacher == 13){
		//return 0.45;
		double temp = 0.1;
		//weight = temp;
		temp2 = &temp;
		//printf("%d\n", temp);
		//printf("End if: %f\n", *temp2);
	} else if(teacher == 2 || teacher == 5 || teacher == 6 || teacher == 9 || teacher == 10 || teacher == 12){
		//return 0.4;
		double temp = 0.2;
		temp2 = &temp;
	} else if(teacher == 11){
		//return 0;
		double temp = 0;
		temp2 = &temp;
	}
	//printf("%d\n",weight);
	//return weight;
}

void rounding_select(int teacher, double round){
	
	/*switch(teacher){
		case 1 : //Baker
			round = 0;
			break;
		case 2 : //Sabatke
			round = 0;
			break;
		case 3 : //Bright
			round = 0.5;
			break;
		case 4 : //Ginorio
			round = 0.5;
			break;
		case 5 : //McCormack
			round = 0.2;
			break;
		case 6 : //Gabrielsen
			round = 0.5;
			break;
		case 7 : //Harrison
			round = 0;
			break;
		case 8 : //Williams
			round = 0;
			break;
		case 9 : //Hall
			round = 0.5;
			break;
		case 10 : //Vaughan
			round = 0.5;
			break;
		case 11 : //Ketchum
			round = 0;
			break;
		case 12 : //Solsvik
			round = 0.2;
			break;
		case 13 : //Rigg
			round = 0;
			break;
		default :
			round = 0;
	}*/
	if(teacher == 1 || teacher == 2 || teacher == 7 || teacher == 8 || teacher == 11 || teacher == 13){
		//return 0.45;
		double temp = 0;
		//weight = temp;
		temp2 = &temp;
		//printf("%d\n", temp);
		//printf("End if: %f\n", *temp2);
	} else if(teacher == 5 || teacher == 12){
		//return 0.4;
		double temp = 0.2;
		temp2 = &temp;
	} else if(teacher == 3 || teacher == 4 || teacher == 6 || teacher == 9 || teacher == 10){
		//return 0;
		double temp = 0.5;
		temp2 = &temp;
	}

	//printf("%d\n",round);
	//return round;
}

