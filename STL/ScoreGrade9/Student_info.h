#ifndef SCOREGRADE9_STUDENT_INFO_H
#define SCOREGRADE9_STUDENT_INFO_H

#include <iostream>
#include <vector>

#include "Core.h"


class Student_info {
public:
    static bool compare(const Student_info& s1, const Student_info& s2);       // 특정 함수와 관계있는 스태틱멤버함수,,,,;?

    Student_info();
    Student_info(std::istream& in);
    Student_info(const Student_info& rhs);
    ~Student_info();

    Student_info& operator=(const Student_info& rhs);

    std::istream& read(std::istream& in);

    std::string name() const;
    double grade() const;

private:
    Core *pCore_;

};

#endif //SCOREGRADE9_STUDENT_INFO_H