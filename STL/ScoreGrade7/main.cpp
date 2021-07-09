#include <iostream>
//#include <ios>
//#include <iomanip>		// manipulator 조력자, 조작자
#include <string>
#include <vector>		// 벡터 ; 가변길이 배열 - 가득찬 후에 넣으려고하면(push_back) 크기가 2배씩 늘어남..
//#include <list>
//#include <algorithm>	// sort사용하기위해
//#include <stdexcept>	// standard_exception

#include "student_info.h"
//#include "grade.h"
//#include "median.h"
//#include "average.h"


using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
//using std::list;
//using std::setprecision;
//using std::istream;
using std::ostream;
using std::streamsize;
using std::max;
//using std::sort;
using std::find;
//using std::transform;
using std::domain_error;
//using std::remove_copy_if;
using std::back_inserter;
//using std::stable_partition;


template <typename T>
//typedef vector<T> Container<T>;
//using Container = list<T>;
using Container = vector<T>;

/*
bool fgrade(const Student_info& s)         // fail_grade
{
    return s.grade() < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
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
/*    Container<Student_info> pass, fail;

    for (auto iter=students.begin() ; iter!=students.end() ; )
    {

        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);        // 지우고 다음원소를 리턴..
        }
        else
            ++iter;
    }
*/
/*
    Container<Student_info> fail;

    remove_copy_if(students.cbegin(), students.cend(), back_inserter(fail), pgrade);

    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    // remove_if 를 하면 다음 위치를 반환하고, 뒤(stuendts.end())까지 지워주면 됨
*/
/*
    auto iter = stable_partition(students.begin(), students.end(), pgrade);     // stable_partition  pass와 fail을 분류해줌
    Container<Student_info> fail(iter, students.end());         // fail 부분은 따로 벡터로 모아줌 -> 리턴시킴

    students.erase(iter, students.end());                       // fail 부분 삭제 -> pass만 남음

    return fail;
}
*/
/*
bool did_all_hw(const Student_info& s)
{
    return find(s.homeworks.cbegin(), s.homeworks.cend(), 0.0) == s.homeworks.cend();
    // 숙제 다했다면(0을 찾지 못했다면) find가 끝까지 감.(이터레이터가 가장 마지막 위치로) -> 끝이랑 같은 위치면 숙제 다함.
}*/
/*

double median_analysis(const Container<Student_info>& students)
{
    Container<double> finalScores;

    //for(Container<Student_info>::const_iterator iter=students.cbegin() ; iter!=students.cend() ; ++iter)
//    for(auto iter=students.cbegin() ; iter!=students.cend() ; ++iter)
//    {
//        finalScores.push_back(grade(*iter));
//    }

    //transform(students.cbegin(), students.cend(), back_inserter(finalScores), grade);
    // students 학생들을 다 꺼내서 grade를 적용시켜서 finalScores에 집어넣음..
    // 오버로딩한 grade를 정확히 찾을 수 없음;...
    transform(students.cbegin(), students.cend(), back_inserter(finalScores), grade_aux);   // grade_auxiliary ; 보조자

    return median(finalScores);
}

double average_analysis(const Container<Student_info>& students)
{
    Container<double> finalScores;
    transform(students.cbegin(), students.cend(), back_inserter(finalScores), grade_average);   // grade_auxiliary ; 보조자
    return median(finalScores); // average(finalScores)
}

double optimistic_median_analysis(const Container<Student_info>& students)
{
    Container<double> finalScores;
    transform(students.cbegin(), students.cend(), back_inserter(finalScores), grade_optimistic_median);   // grade_auxiliary ; 보조자
    return median(finalScores);
}



void write_analysis(ostream& out, const string& name, double analysis(const Container<Student_info>&),
                    const Container<Student_info>& did, const Container<Student_info>& didnt)
{
    out << name << endl;
    out << "did   : " << analysis(did) << endl;
    out << "didnt : " << analysis(didnt) << endl;
}
*/

int main()
{

	string::size_type maxLen = 0;
	Container<Student_info> students;
    //Container<Student_info> did, didnt;


	Student_info student;
	//while (read(cin, student))
	while(student.read(cin))
	{
		maxLen = max(maxLen, student.name().size());
		students.push_back(student);
//		if(did_all_hw(student))
//		    did.push_back(student);
//		else
//		    didnt.push_back(student);

	}

	try
	{
        for(auto iter = students.cbegin(); iter!=students.cend(); ++iter)
            cout << iter->name() << string(maxLen - iter->name().size(), ' ')
                 << " : "  << iter->grade() << endl;
	}
    catch (domain_error& e)
    {

    }

/*
	if (did.empty())
    {
	    cout << "no student did all homework" << endl;
	    return 1;
    }

	if (didnt.empty())
    {
	    cout << "every student did all homework" << endl;
	    return 1;
    }


	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "optimistic_median", optimistic_median_analysis, did, didnt);
*/
/*
	sort(students.begin(), students.end(), compare);
	//students.sort(compare);         // 링크드리스트 내부함수로 정렬


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
*/
	return 0;
}