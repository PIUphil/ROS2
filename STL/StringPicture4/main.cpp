#include <iostream>
#include <algorithm>
//#include <vector>
//#include <string>
#include "Vec.h"
#include "Str.h"
#include "Picture.h"
#include "Student_info.h"

using namespace std;


Picture histogram(const Vec<Student_info>& students)
{
    Picture names;
    Picture grades;

    for(Vec<Student_info>::const_iterator it = students.cbegin() ; it!=students.cend() ; ++it)
    {
        names = Picture::vcat(names, Vec<Str>(1, Str(it->name().c_str())));
        grades = Picture::vcat(grades, Vec<Str>(1, Str(it->grade()/5, '=')));
    }

    return Picture::hcat(names, grades);
}


int main()
{
    /*
    Vec<Str> words;
    words.push_back("wonderful tonight");
    words.push_back("just the way you are");
    words.push_back("butter");
    words.push_back("knocking on the heaven's door");

    Picture pic = words;
    cout << pic;

    Picture pic2 = Picture::frame(pic);
    cout << pic2;
    // cout << Picture::frame(pic2);

    Picture::reframe('#');

    Picture pic3 = Picture::vcat(pic, pic2);
    cout << pic3;

    Picture pic4 = Picture::hcat(pic, pic2);
    cout << pic4;
    */


    Vec<Student_info> students;
    Student_info s;

    while (s.read(cin))
        students.push_back(s);

    std::sort(students.begin(), students.end(), Student_info::compare);

    cout << Picture::frame(histogram(students)) << endl;


    return 0;
}
