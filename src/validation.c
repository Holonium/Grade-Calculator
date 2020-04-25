#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int verify_classes(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify < 1){
		return 1;
	} else if(verify > 8){
		return 1;
	}
	return 0;
}

int verify_teachers(char *input){
	int verify = atoi(input);
	if(verify == 0){
		return 1;
	} else if(verify > 14){
		return 1;
	} else if(verify < 1){
		return 1;
	}
	return 0;
}

int verify_grades(char *input){
	double verify = atof(input);
	if(verify <= 0){
		return 1;
	}
	return 0;
}

int verify_constants(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 0;
	} else if(verify < 0){
		return 1;
	} else if(verify > 1){
		return 1;
	}
	return 0;
}

int verify_credits(char *input){
	double verify = atof(input);
	if(verify <= 0){
		return 1;
	}
	return 0;
}

int verify_final(char *input){
	double verify = atof(input);
	if(verify == 0){
		return 1;
	} else if(verify < 0){
		return 1;
	} else if(verify > 1){
		return 1;
	}
	return 0;
}

int verify_type(char *input){
	int verify = atoi(input);
	if(verify <= 0){
		return 1;
	} else if(verify > 3){
		return 1;
	}
	return 0;
}

int verify_year(char *input){
	int verify = atoi(input);
	if(verify <= 0){
		return 1;
	} else if(verify > 4){
		return 1;
	}
	return 0;
}

int verify_semester(char *input){
	int verify = atoi(input);
	if(verify <= 0){
		return 1;
	} else if(verify > 2){
		return 1;
	}
	return 0;
}
