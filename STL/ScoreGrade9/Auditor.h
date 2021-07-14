#ifndef SCOREGRADE9_AUDITOR_H
#define SCOREGRADE9_AUDITOR_H

#include <iostream>

#include "Core.h"


class Auditor : public Core
{
friend class Student_info;

//public:
private:
    Auditor();
    Auditor(std::istream& in);
    virtual ~Auditor() {}

    virtual std::istream& read(std::istream& in);
    virtual double grade() const;

    virtual Core* clone() const;

};


#endif //SCOREGRADE9_AUDITOR_H
