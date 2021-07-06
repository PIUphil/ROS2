#include <iostream>
#include <vector>

#include "student_info.h"
#include "grade.h"

using std::vector;
using std::istream;


istream& read_hw(istream& in, vector<double>& homeworks)
{
	if (in) {
		homeworks.clear();				// 벡터 비움
	
		double hw;
		while (in >> hw) {
			homeworks.push_back(hw);
		}

		in.clear();			

	}
	return in;
}

/*
istream& read(istream& in, Student_info& student)
{
	in >> student.name >> student.midterm >> student.finalterm;

	read_hw(in, student.homeworks);

	return in;
}
*/

istream& read(istream& in, Student_info& student)
{
	double midterm, finalterm;
	in >> student.name >> midterm >> finalterm;

	vector<double> homeworks;
	read_hw(in, homeworks);
	
	if (in)
		student.finalScore = grade(midterm, finalterm, homeworks);

	return in;
}


bool compare(const Student_info& s1, const Student_info& s2)
{
	return s1.name < s2.name;
}


