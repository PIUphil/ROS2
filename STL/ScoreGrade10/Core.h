#ifndef SCOREGRADE9_CORE_H
#define SCOREGRADE9_CORE_H


#include <iostream>
#include <string>
#include <vector>

#include "Handle.h"


class Core;
//bool compare(const Core& s1, const Core& s2);
//bool compare_ptr(const Core *pCore1, const Core *pCore2);
bool compare_handle(const Handle<Core>& h1, const Handle<Core>& h2);

std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);


class Core {
friend class Student_info;
public:
//protected:
    Core();
    Core(std::istream& in);
    virtual ~Core() {}              // 버츄얼을 한번이라도 사용하면 소멸자도 버츄얼로 만들어줘야함,,

    std::string name() const;
    void regrade(double finalterm);

    virtual std::istream& read(std::istream& in);
    virtual double grade() const;

    virtual Core* clone() const;

protected:
    double midterm_;
    double finalterm_;
    std::vector<double> homeworks_;

    std::istream& read_common(std::istream& in);

private:
    std::string name_;

};


#endif //SCOREGRADE9_CORE_H
