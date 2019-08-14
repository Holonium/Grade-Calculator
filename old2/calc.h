#ifndef CALC_H_
#define CALC_H_

//Functions
extern int validateTeacher(int teachers, int range);
extern int *roundPercents(int *percentsRaw, int *roundingFactors, int *percents);
extern int *determineFinals(int *q12grades, int *finalWeight, int *finals);
extern int *combineQuarters(int *quarterWeight, int *quarterGrade, int *q12grades);
extern int *teacherRound(int *teachers, int *roundingFactors);
extern int *teacherQweight(int *teachers, int *quarterWeight);
extern int *teacherFweight(int *teachers, int *finalWeight);
#endif
