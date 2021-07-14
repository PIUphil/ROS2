#include "Core.h"
#include "grade.h"

/*
bool compare(const Core& s1, const Core& s2)
{
    return s1.name() < s2.name();               // 알파벳순 비교
}

bool compare_ptr(const Core *pCore1, const Core *pCore2)
{
    return pCore1->name() < pCore2->name();
}
*/

std::istream& read_hw(std::istream& in, std::vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
            homeworks.push_back(homework);

        in.clear();
    }

    return in;
}


std::istream& Core::read_common(std::istream& in)
{
    return in >> this->name_ >> this->midterm_ >> this->finalterm_;
}


Core::Core()
    : name_(), midterm_(0.0), finalterm_(0.0), homeworks_()
{}

Core::Core(std::istream &in)
{
    this->read(in);
}


void Core::regrade(double finalterm)
{
    this->finalterm_ = finalterm;
}


std::istream& Core::read(std::istream& in)
{
//    in >> this->name_;
//    in >> this->midterm_ >> this->finalterm_;
    this->read_common(in);
    ::read_hw(in, this->homeworks_);                // 전역함수


    return in;
}

std::string Core::name() const
{
    return this->name_;
}

double Core::grade() const
{
    return ::grade(this->midterm_, this->finalterm_, this->homeworks_);
}

Core* Core::clone() const
{
    return new Core(*this);             // 자신과 같은 복제본 생성
}