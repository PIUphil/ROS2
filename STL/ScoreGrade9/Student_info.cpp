#include <stdexcept>

#include "Core.h"
#include "Grad.h"
#include "Auditor.h"
#include "Student_info.h"

bool Student_info::compare(const Student_info& s1, const Student_info& s2)      // static멤버함수,,
{
    return s1.name() < s2.name();
}


Student_info::Student_info()
    : pCore_(0)
{}

Student_info::Student_info(std::istream& in)
    : pCore_(0)
{
    this->read(in);
}

Student_info::Student_info(const Student_info& rhs)
{
    if (rhs.pCore_)
        pCore_ = rhs.pCore_->clone();
    else
        pCore_ = 0;
}

Student_info::~Student_info()
{
    delete pCore_;
}


Student_info& Student_info::operator=(const Student_info& rhs)
{
    if (this != &rhs)
    {
        delete pCore_;

        if(rhs.pCore_)
            pCore_ = rhs.pCore_->clone();
        else
            pCore_ = 0;
    }

    return *this;
}


std::istream& Student_info::read(std::istream& in)
{
    delete pCore_;      // 기존에 pCore_가 있으면 지우고, null일때도 작동시켜도 됨,, 어차피 작동 안할거니까
    pCore_ = 0;

    char ch;
    in >> ch;

    if (ch=='U')
        pCore_ = new Core(in);
    else if (ch=='G')
        pCore_ = new Grad(in);
    else if (ch=='A')
        pCore_ = new Auditor(in);

    return in;
}

std::string Student_info::name() const
{
    if (pCore_)
        return pCore_->name();
    else
        throw std::runtime_error("uninitialized student");
}

double Student_info::grade() const
{
    if (pCore_)
        return pCore_->grade();
    else
        throw std::runtime_error("uninitialized student");
}