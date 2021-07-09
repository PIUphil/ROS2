#include <iostream>
#include <vector>
#include <string>

#include "student_info.h"
#include "grade.h"

using std::vector;
using std::string;
using std::istream;
using std::domain_error;


istream& read_hw(istream& in, vector<double>& homeworks_)
{
	if (in) {
		homeworks_.clear();				// 벡터 비움
	
		double hw;
		while (in >> hw) {
			homeworks_.push_back(hw);
		}

		in.clear();			
	// 숙제를 몇개 받을지 모르고, (여러명의 학생을 받을 때) 두번째줄에 이름을 받는데, 그때 더블형이 되어있어서
	// cin내부적으로 오류가 생김 (이름은 스트링인데, 더블로 되어있어서),, 그래서 클리어 해줌,,,

	}
	return in;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    //return s1.name_ < s2.name_;       // private이므로 get함수를 이용하여 가져옴
    return s1.name() < s2.name();
}



// istream& Student_info::read(istream& in, Student_info& student)
istream& Student_info::read(istream& in)
{
	in >> this->name_ >> this->midterm_ >> this->finalterm_;

	read_hw(in, this->homeworks_);

	return in;
}



Student_info::Student_info()
    : name_(), midterm_(0.0), finalterm_(0.0), homeworks_()     //homeworks_는 벡터라서 빈칸으로 만들어짐
{}

Student_info::Student_info(istream& in)
{
    this->read(in);
}



string Student_info::name() const
{
    return this->name_;
}


bool Student_info::valid() const
{
    return !this->homeworks_.empty();
}


double Student_info::grade() const
{
    if (this->valid() )
        return ::grade(this->midterm_, this->finalterm_, this->homeworks_);        // ::만 쓰면 전역함수라는 의미
    else
        return ::grade(this->midterm_, this->finalterm_, 0.0);
}