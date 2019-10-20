//This file handles the return of teacher constants.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

double q1weight_select(int teacher){
	double weight;

	switch(teacher){
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
	}

	return weight;
}

double q2weight_select(int teacher){
	double weight;

	switch(teacher){
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
	}

	return weight;
}

double fweight_select(int teacher){
	double weight;
	
	switch(teacher){
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
	}

	return weight;
}

double rounding_select(int teacher){
	double round;
	
	switch(teacher){
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
	}
	return round;
}

