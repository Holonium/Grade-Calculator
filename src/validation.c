#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int verify_classes(int input){
	if(input <= 0){
		return 1;
	} else if(input > 8){
		return 1;
	}
	return 0;
}

int verify_teachers(int input){
	if(input <= 0){
		return 1;
	} else if(input > 14){
		return 1;
	}
	return 0;
}

int verify_grades(double input){
	if(input <= 0){
		return 1;
	}
	return 0;
}

int verify_constants(double input){
	if(input == 0){
		return 0;
	} else if(input < 0){
		return 1;
	} else if(input > 1){
		return 1;
	}
	return 0;
}

int verify_credits(double input){
	if(input <= 0){
		return 1;
	}
	return 0;
}

int verify_final(double input){
	if(input <= 0){
		return 1;
	} else if(input > 1){
		return 1;
	}
	return 0;
}

int verify_type(int input){
	if(input <= 0){
		return 1;
	} else if(input > 3){
		return 1;
	}
	return 0;
}

int verify_year(int input){
	if(input <= 0){
		return 1;
	} else if(input > 3){
		return 1;
	}
	return 0;
}

int verify_semester(int input){
	if(input <= 0){
		return 1;
	} else if(input > 2){
		return 1;
	}
	return 0;
}

int verify_letter(char input){
	char reference[] = {'A', 'B', 'C', 'D', 'F'};
	for(int i = 0; i < 5; i++){
		if(input == reference[i]){
			return 0;
		}
	}
	return 1;
}

int verify_sign(char input){
	char reference[] = {'\0', '+', '-'};
	for(int i = 0; i < 3; i++){
		if(input == reference[i]){
			return 0;
		}
	}
	return 1;
}
