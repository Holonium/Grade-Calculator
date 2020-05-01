#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int verify_YN(char input){
		if(input == 'Y'){
			return 0;
		} else if(input == 'N'){
			return 0;
		} else {
			return 1;
		}
}
