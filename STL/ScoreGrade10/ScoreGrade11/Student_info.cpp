#include <stdexcept>

#include "Core.h"
#include "Grad.h"
//#include "Auditor.h"
#include "Student_info.h"

bool Student_info::compare(const Student_info& s1, const Student_info& s2)      // static멤버함수,,
{
    return s1.name() < s2.name();
}


Student_info::Student_info()
    : handle_()
{}

Student_info::Student_info(std::istream& in)
    : handle_()
{
    this->read(in);
}


std::istream& Student_info::read(std::istream& in)
{
    char ch;
    in >> ch;

    if (ch=='U')
        handle_ = new Core(in);
    else if (ch=='G')
        handle_ = new Grad(in);
//    else if (ch=='A')
//        //pCore_ = new Auditor(in);
//        handle_ = new Auditor(in);

    return in;
}

std::string Student_info::name() const
{
    if (handle_)
        return handle_->name();
    else
        throw std::runtime_error("uninitialized student");
}

double Student_info::grade() const
{
    if (handle_)
        return handle_->grade();
    else
        throw std::runtime_error("uninitialized student");
}