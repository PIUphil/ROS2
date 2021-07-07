#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>
// 헤더파일에선 using 사용x

struct Student_info {
	std::string name;
	double midterm;
	double finalterm;
	std::vector<double> homeworks;
};


std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);

std::istream& read(std::istream& in, Student_info& student);

bool compare(const Student_info& s1, const Student_info& s2);

#endif
