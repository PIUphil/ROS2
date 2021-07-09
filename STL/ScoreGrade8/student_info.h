#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>


class Student_info {
private:
	std::string name_;
//	double midterm_;
//	double finalterm_;
//	std::vector<double> homeworks_;
	double finalScore_;

	
public:
    Student_info();
    Student_info(std::istream& in);


    //std::istream& read(std::istream& in, Student_info& student);
    std::istream& read(std::istream& in);

    std::string name() const;       // get_name 함수

    bool valid() const;             // 숙제 하나라도 했는지

    //double grade() const;
    double score() const;           // get_finalScore
};


std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);

bool compare(const Student_info& s1, const Student_info& s2);

#endif
