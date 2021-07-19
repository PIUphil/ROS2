#ifndef SCOREGRADE9_GRADE_H
#define SCOREGRADE9_GRADE_H

#include <vector>

double grade(double midterm, double finalterm, double homework);
double grade(double midterm, double finalterm, const std::vector<double>& homeworks);      // 중앙값 구하려면 sort해야해서 레퍼런스 말고 밸류로 넘김

// double grade(const Student_info& student);
// double grade_aux(const Student_info& student);


#endif //SCOREGRADE9_GRADE_H
