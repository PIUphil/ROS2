#include <iostream>
#include <vector>
#include <algorithm>            // sort, max
#include <stdexcept>            // domain_error
#include <string>
#include <ios>
#include <iomanip>              // precision, setprecision
#include <typeinfo>


#include "Student_info.h"
//#include "Core.h"
//#include "Grad.h"


using namespace std;


int main()
{
    //vector<Core *> students;                // 포인터로 만들어두면 부모,자식 다 가리킬 수 있다
    vector<Student_info> students;                // 포인터로 만들어두면 부모,자식 다 가리킬 수 있다

    string::size_type maxLen = 0;


    char ch;
    Student_info student;
    while (student.read(cin))
    {
        students.push_back(student);
        maxLen = max(maxLen, student.name().size());
    }


    sort(students.begin(), students.end(), Student_info::compare);
    //sort(students.begin(), students.end(), compare_ptr);


    //for(vector<Core>::const_iterator iter=students.cbegin() ; iter!= students.cend() ; ++iter)
    //for(auto iter=students.cbegin() ; iter!= students.cend() ; ++iter)
    for(Student_info student : students)                   // 배열(벡터)로부터 값을 꺼내올 때 사용. (ptr in students)
    {
//        if(typeid(*iter)==typeid(Core))
//            cout <<"U";
//        else if(typeid(*iter)==typeid(Grad))
//            cout <<"G";
//        if(typeid(*ptr)==typeid(Core))
//            cout <<"U ";
//        else if(typeid(*ptr)==typeid(Grad))
//            cout <<"G ";


        //cout << (*iter)->name() << string(maxLen-(*iter)->name().size(), ' ') << " : ";
        cout << student.name() << string(maxLen-student.name().size(), ' ') << " : ";

        try
        {
            //double score = (*iter)->grade();            // grade가 동적바인딩이 되어 학생/대학원생 나눠져 연결
            double score = student.grade();            // grade가 동적바인딩이 되어 학생/대학원생 나눠져 연결
            streamsize ss = cout.precision();
            cout << setprecision(3) << score << setprecision(ss) << endl;
        }
        catch (domain_error e)
        {
            cerr << e.what() << endl;
        }

    }

//    for(auto iter=students.begin() ; iter!=students.end() ; ++iter)
//        delete (*iter);

    /*
    Core *pCore = new Grad();           // 부모클래스의 포인터는 자식클래스의 객체를 가리킬 수 있다  // 다형성 polymorphism
    pCore->read(std::cin);
    pCore->grade();

    delete pCore;
     */

    return 0;
}
