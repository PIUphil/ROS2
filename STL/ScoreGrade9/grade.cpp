#include "median.h"
#include "grade.h"



double grade(double midterm, double finalterm, double homework)
{
    return 0.2*midterm+0.4*finalterm+0.4*homework;
}

double grade(double midterm, double finalterm, const std::vector<double>& homeworks)
{
    return ::grade(midterm, finalterm, median(homeworks));
}

