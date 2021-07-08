#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <cctype>

#include "student_info.h"
#include "../scoreGrade6/average.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::find_if;


char Grade(const Student_info& student)
{
    switch((int)grade(student)/10)
    {
    case 10: case 9:
        return 'A';
    case 8:
        return 'B';
    case 7:
        return 'C';
    case 6:
        return 'D';
    default:
        return 'F';
    }
}


int main()
{
    map<char, vector<string> > stu;
    vector<Student_info> students;

    Student_info student;
    while (read(cin, student)) {
        //maxLen = max(maxLen, student.name.size());
        students.push_back(student);
    }

    for (auto iter=students.cbegin() ; iter!=students.cend() ; ++iter)
    {
        stu[Grade(*iter)].push_back(iter->name);
    }

    for (auto iter=stu.cbegin() ; iter!=stu.cend() ; ++iter)
    {
        cout << iter->first << " - ";

        for (auto iter2=iter->second.cbegin() ; iter2!=iter->second.cend() ; ++iter2)
        {
            cout << *iter2 << ", ";
        }

        cout << endl;
    }

    return 0;
}
