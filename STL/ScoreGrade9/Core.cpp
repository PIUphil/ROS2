#include "Core.h"
#include "grade.h"


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