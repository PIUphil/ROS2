#ifndef SCOREGRADE9_GRAD_H
#define SCOREGRADE9_GRAD_H


#include "Core.h"

class Grad : public Core {
    friend class Student_info;

public:
//private:
    Grad();
    Grad(std::istream& in);
    virtual ~Grad() {}

    void regrade(double finalterm, double thesis);

    virtual std::istream& read(std::istream& in);
    virtual double grade() const;

    virtual Core* clone() const;        // 오버라이딩

private:
    double thesis_;

};


#endif //SCOREGRADE9_GRAD_H
