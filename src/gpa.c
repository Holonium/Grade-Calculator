#include <stdio.h>
#include "functions.h"
#include "results.h"

double hsGPA_unweight_class(double qgrade, double credits){
	double unmod;
	double gpa = 4;
	for(int i = 0; i < 11; i++){
		int j = i + 1;
		if(i == 0){
			if(qgrade >= percentagesRaw[i]){
				unmod = gpa;
				i = 11;
			}
		}else if(i > 0){
			if(qgrade >= percentagesRaw[j] && qgrade < percentagesRaw[i]){
				unmod = gpa - (0.33 * i);
				i = 11;
			}
		}
	}
	
	/*if(qgrade >= 93){
		unmod = 4.00;
	}else if(qgrade >= 90 && qgrade < 93){
		unmod = 3.67;
	}else if(qgrade >= 87 && qgrade < 90){
		unmod = 3.33;
	}else if(qgrade >= 83 && qgrade < 87){
		unmod = 3.00;
	}else if(qgrade >= 80 && qgrade < 83){
		unmod = 2.67;
	}else if(qgrade >= 77 && qgrade < 80){
		unmod = 2.33;
	}else if(qgrade >= 73 && qgrade < 77){
		unmod = 2.00;
	}else if(qgrade >= 70 && qgrade < 73){
		unmod = 1.67;
	}else if(qgrade >= 67 && qgrade < 70){
		unmod = 1.33;
	}else if(qgrade >= 63 && qgrade < 67){
		unmod = 1.00;
	}else if(qgrade >= 60 && qgrade < 63){
		unmod = 0.67;
	}else if(qgrade < 60){
		unmod = 0.00;
	}*/
	double gradePoints = unmod * credits;
	return gradePoints;
}

double hsGPA_weight_class(double qgrade, int type, double credits){
	double unmod;
	double gpa = 4;
	for(int i = 0; i < 11; i++){
		int j = i + 1;
		if(i == 0){
			if(qgrade >= percentagesRaw[i]){
				unmod = gpa;
				i = 11;
			}
		}else if(i > 0){
			if(qgrade >= percentagesRaw[j] && qgrade < percentagesRaw[i]){
				unmod = gpa - (0.33 * i);
				i = 11;
			}
		}
	}
	
	if(type == 0){
		unmod = unmod + 0;
	}else if(type == 1){
		unmod = unmod + 0.5;
	}else if(type == 2){
		unmod = unmod + 1;
	}
	double gradePoints = unmod * credits;
	return gradePoints;
}

double hsGPA_unweight_semester(double gradePointsSum, double totalCredits){
	double GPA = gradePointsSum / totalCredits;
	return GPA;
}

double hsGPA_weight_semester(double gradePointsSum, double totalCredits){
	double GPA = gradePointsSum / totalCredits;
	return GPA;
}

double hsGPA_unweight_full(double gradePoints1, double credits1, double gradePoints2, double credits2, double gradePoints3, double credits3, double gradePoints4, double credits4){
	double gradePointsSum = gradePoints1 + gradePoints2 + gradePoints3 + gradePoints4;
	double totalCredits = credits1 + credits2 + credits3 + credits4;
	double GPA = gradePointsSum / totalCredits;
	return GPA;
}

double hsGPA_weight_full(double gradePoints1, double credits1, double gradePoints2, double credits2, double gradePoints3, double credits3, double gradePoints4, double credits4){
	double gradePointsSum = gradePoints1 + gradePoints2 + gradePoints3 + gradePoints4;
	double totalCredits = credits1 + credits2 + credits3 + credits4;
	double GPA = gradePointsSum / totalCredits;
	return GPA;
}
