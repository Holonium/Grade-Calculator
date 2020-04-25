#ifndef GRADES_H_
#define GRADES_H_

const char version[] = "v1.0.0a1";
const double percentagesRaw[] = {93,90,87,83,80,77,73,70,67,63,60};
const char grades[] = {'A','A','B','B','B','C','C','C','D','D','D'};
const char symbol[] = {'\0','-','+','\0','-','+','\0','-','+','\0','-'};
const double gpa = 4.00;
const char *teacher_list_charter = "1) Mrs. Baker\n2) Mr. Sabatke\n3) Ms. Bright\n4) Mr. Ginorio\n5) Mr. McCormack\n6) Mr. Gabrielsen\n7) Mr. Harrison\n8) Mr. Williams\n9) Mr. Hall\n10) Mrs. Vaughan\n11) Mrs. Ketchum\n12) Ms. Solsvik\n13) Mr. Rigg\n14) Other\nPlease enter the number of the teacher for period ";
const char *class_types = "1) Standard\n2) Honors\n3) AP\nPlease enter the number of the class type for period ";
char *grade1 = "What is your grade for the ";
char *grade2 = " quarter of this semester? ";

char *guaranteed1 = "You are guaranteed to get at least an ";
char *guaranteed2 = "You are guaranteed to get at least a ";
char *guaranteed3 = " for the semester!";

char *out1 = "You need at least a ";
char *out2 = " to get a ";
char *out3 = " for this semester.";

#endif
