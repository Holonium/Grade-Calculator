//Validation of inputs.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "calc.h"

int validateTeacher(int teachers[6], int range){
	int valid[6];
	int valid1[6];
	int valid2[6];
	int i;
	int v = 1;
	for(i = 0; i < 6; i++){
		if(teachers[i] <= range){
			valid1[i] = 1;
		} else {
			valid1[i] = 0;
		}
		if(teachers[i] > 0){
			valid2[i] = 1;
		} else {
			valid2[i] = 0;
		}
	}
	for(i = 0; i < 6; i++){
		if(valid1[i] == 0 || valid2[i] == 0){
			v = 0;
		}
	}
	return v;
}
