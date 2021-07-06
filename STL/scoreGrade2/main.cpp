#include <iostream>
#include <ios>
#include <iomanip>		// manipulator 조력자, 조작자
#include <string>
#include <vector>		// 벡터 ; 가변길이 배열 - 가득찬 후에 넣으려고하면(push_back) 크기가 2배씩 늘어남..
#include <algorithm>	// sort사용하기위해
#include <stdexcept>	// standard_exception

#include "student_info.h"
//#include "grade.h"
//#include "median.h"


using std::cin;
using std::cout;
using std::cerr;
using std::endl;
//using std::istream;
using std::string;
using std::vector;
using std::setprecision;
using std::streamsize;
using std::max;
using std::sort;
using std::domain_error;



int main()
{

	string::size_type maxLen = 0;
	vector<Student_info> students;

	try {
		Student_info student;
		while (read(cin, student)) {
			maxLen = max(maxLen, student.name.size());
			students.push_back(student);
		}
	} catch (const domain_error& e) {
		cerr << endl << e.what() << endl;
		return 1;
	}

	sort(students.begin(), students.end(), compare);	


	for(vector<Student_info>::size_type i = 0; i!=students.size(); ++i)
	{
		streamsize ss = cout.precision();

		cout << students[i].name << string(maxLen - students[i].name.size(), ' ') 
			 << " : " << setprecision(3)
//	 			 << grade(students[i]) << setprecision(ss) << endl;
 			 << students[i].finalScore << setprecision(ss) << endl;
	}
	

	return 0;
}
