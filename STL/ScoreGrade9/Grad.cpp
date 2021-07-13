#include <algorithm>
#include "Grad.h"

Grad::Grad()
    : Core(), thesis_(0.0)
{}

/*
Grad::Grad(std::istream& in)
    : Core(in)
{}*/

std::istream& Grad::read(std::istream& in)
{
    this->Core::read_common(in);
    in >> this->thesis_;
    ::read_hw(in, this->Core::homeworks_);
}

double Grad::grade() const
{
    return std::min(this->Core::grade(), this->thesis_);
}

