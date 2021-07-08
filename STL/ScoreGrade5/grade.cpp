#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

#include "student_info.h"
#include "median.h"
#include "grade.h"
#include "average.h"

using std::vector;
using std::domain_error;
using std::remove_copy;
using std::back_inserter;


double grade(double midterm, double finalterm, double homework)
{
	return 0.2*midterm + 0.4*finalterm + 0.4*homework;
}

double grade(double midterm, double finalterm, const vector<double>& homeworks)
{
	if (homeworks.size()==0)
	{
		// throw 0;
		throw domain_error("students didn't any homework");
	}

	return grade(midterm, finalterm, median(homeworks));
}

double grade(const Student_info& student)
{
	return grade(student.midterm, student.finalterm, student.homeworks);
}


double grade_aux(const Student_info& student)
{
    try
    {
        return grade(student);
    }
    catch(domain_error)
    {
        return grade(student.midterm, student.finalterm, 0.0);
    }
}

double grade_average(const Student_info& student)
{
    return grade(student.midterm, student.finalterm, average(student.homeworks));
}

double grade_optimistic_median(const Student_info& student)
{
    vector<double> nonzero;                 // 0점을 제거하고 nonzero 벡터에 넣어줌
    remove_copy(student.homeworks.cbegin(), student.homeworks.cend(), back_inserter(nonzero), 0.0);

    if (nonzero.empty())
        return grade(student.midterm, student.finalterm, 0.0);
    else
        return grade(student.midterm, student.finalterm, nonzero);
}