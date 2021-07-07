#include <iostream>
#include <ios>
#include <iomanip>		// manipulator 조력자, 조작자
#include <string>
//#include <vector>		// 벡터 ; 가변길이 배열 - 가득찬 후에 넣으려고하면(push_back) 크기가 2배씩 늘어남..
#include <list>
#include <algorithm>	// sort사용하기위해
#include <stdexcept>	// standard_exception

#include "student_info.h"
#include "grade.h"
#include "median.h"


using std::cin;
using std::cout;
using std::cerr;
using std::endl;
//using std::istream;
using std::string;
//using std::vector;
using std::list;
using std::setprecision;
using std::streamsize;
using std::max;
using std::sort;
using std::domain_error;

template <typename T>
//typedef vector<T> Container<T>;
using Container = list<T>;


bool fgrade(const Student_info& s)         // fail_grade
{
    return grade(s) < 60;
}


//vector<Student_info> extract_fails(vector<Student_info>& students)      // 60점이하 불합격생 추출. 합격생은 그대로남김
//{
//    vector<Student_info> pass, fail;
//    for (vector<Student_info>::size_type i=0 ; i!=students.size() ; ++i)
//    {
//        if(fgrade(students[i]))
//            fail.push_back(students[i]);
//        else
//            pass.push_back(students[i]);
//    }
//
//    students = pass;
//    return fail;
//}

Container<Student_info> extract_fails(Container<Student_info>& students)
{
    Container<Student_info> pass, fail;
    //for (Container<Student_info>::size_type i=0 ; i!=students.size() ; )   // fail이면 빼내고, 다음것이 빈자리를 알아서 채우기때문에 ++를 안해줌
    //typedef Container<Student_info>::iterator vec_iter;
    //for (vec_iter iter=students.begin() ; iter!=students.end() ; )
    for (auto iter=students.begin() ; iter!=students.end() ; )
    {
        /*
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);     // i번째 제거   //iterate
        }         // erase할때마다 size가 줄어드므로 size()함수를 새로 정의하면 안됨..// auto size = students.size() 하지말기
        else
            ++i;*/
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);        // 지우고 다음원소를 리턴..
        }
        else
            ++iter;
    }

    return fail;
}


int main()
{

	string::size_type maxLen = 0;
	Container<Student_info> students;

	Student_info student;
	while (read(cin, student)) {
		maxLen = max(maxLen, student.name.size());
		students.push_back(student);
	}

	//sort(students.begin(), students.end(), compare);
	students.sort(compare);         // 링크드리스트 내부함수로 정렬


	try {

		//for(Container<Student_info>::size_type i = 0; i!=students.size(); ++i)
//		typedef Container<Student_info>::iterator vec_iter;
//        for(vec_iter iter = students.begin(); iter!=students.end(); ++iter)
        typedef Container<Student_info>::const_iterator vec_citer;
        for(vec_citer iter = students.cbegin(); iter!=students.cend(); ++iter)
		{
			streamsize ss = cout.precision();

			cout << iter->name << string(maxLen - iter->name.size(), ' ')
				 << " : " << setprecision(3)
	 			 << grade((*iter))  << setprecision(ss) << endl;
		}
	} catch (const domain_error& e) {
		cerr << endl << e.what() << endl;
		return 1;
	}


	Container<Student_info> pass = students;
	Container<Student_info> fail = extract_fails(pass);

	cout << "pass list : ";
//	for (Container<Student_info>::size_type i=0 ; i!=pass.size() ; ++i)
//	    cout << pass[i].name << " ";

    typedef Container<Student_info>::const_iterator vec_citer;
    // const_iterator  - 이터레이터 하면서 값을 안바꿀거면(read only)
    // cbegin() - 시작위치 주소를 넘겨주는데 const로,,

    for(vec_citer iter = pass.cbegin() ; iter!=pass.cend() ; ++iter)
        cout << iter->name << " ";

    cout << endl;


	cout << "fail list : ";
//	for (Container<Student_info>::size_type i=0 ; i!=fail.size() ; ++i)
//	    cout << fail[i].name << " ";

    for(vec_citer iter = fail.cbegin() ; iter!=fail.cend() ; ++iter)
        cout << iter->name << " ";

    cout << endl;

	return 0;
}
