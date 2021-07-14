#include <istream>

#include "Auditor.h"


Auditor::Auditor()
//    : Core()          // 생략가능
{}

Auditor::Auditor(std::istream& in)
    : Core()
{
    this->read(in);
}


std::istream& Auditor::read(std::istream& in)
{
//    this->Core::read_common(in);
//    ::read_hw(in, this->Core::homeworks_);

    this->Core::read(in);
}

double Auditor::grade() const
{
    if (this->Core::homeworks_.empty())                    // Core:: 생략가능 // this-> 생략가능
        return (this->midterm_ + this->finalterm_) / 2.0;
    else
        return this->Core::grade();
}

Core* Auditor::clone() const
{
    return new Auditor(*this);
}