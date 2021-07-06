#include <iostream>
#include <ios>
#include <iomanip>		// manipulator 조력자, 조작자
#include <string>
#include <vector>		// 벡터 ; 가변길이 배열 - 가득찬 후에 넣으려고하면(push_back) 크기가 2배씩 늘어남..
#include <algorithm>	// sort사용하기위해
#include <stdexcept>	// standard_exception

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::string;
using std::vector;
using std::setprecision;
using std::streamsize;
using std::max;
using std::sort;
using std::domain_error;


struct Student_info {
	string name;
	double midterm;
	double finalterm;
	vector<double> homeworks;
};


 double median(vector<double> vec) 
{
	if (vec.size()==0) {
		// throw 0;
		throw domain_error("vector is empty");
	}

	sort(vec.begin(), vec.end());
	vector<double>::size_type mid = vec.size() / 2;
	double median = (vec.size() % 2) ? vec[mid] : (vec[mid] + vec[mid-1]) / 2;

	return median;
}


double grade(double midterm, double finalterm, double homework)
{
	return 0.2*midterm + 0.4*finalterm + 0.4*homework;
}

double grade(double midterm, double finalterm, const vector<double>& homeworks)
{
	if (homeworks.size()==0)
	{
		// throw 0;
		throw domain_error("students didn't any homework");
	}

	return grade(midterm, finalterm, median(homeworks));
}

double grade(const Student_info& student)
{
	return grade(student.midterm, student.finalterm, student.homeworks);
}



istream& read_hw(istream& in, vector<double>& homeworks)
{
	if (in) {
		homeworks.clear();				// 벡터 비움
	
		double hw;
		while (cin >> hw) {
			homeworks.push_back(hw);
		}

		in.clear();			
	// 숙제를 몇개 받을지 모르고, (여러명의 학생을 받을 때) 두번째줄에 이름을 받는데, 그때 더블형이 되어있어서
	// cin내부적으로 오류가 생김 (이름은 스트링인데, 더블로 되어있어서),, 그래서 클리어 해줌,,,

	}
	return in;
}


istream& read(istream& in, Student_info& student)
{
	in >> student.name >> student.midterm >> student.finalterm;

	read_hw(in, student.homeworks);

	return in;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
	return s1.name < s2.name;
}


int main()
{

	string::size_type maxLen = 0;
	vector<Student_info> students;

	Student_info student;
	while (read(cin, student)) {
		maxLen = max(maxLen, student.name.size());
		students.push_back(student);
	}

	sort(students.begin(), students.end(), compare);		// 학생 이름순 정렬 (아스키코드 오름차순)


//	cout << "input your name : ";
//	string name;
//	cin >> name;

//	cout << "input your midterm final homework : ";
//	double midterm, finalterm;
//	cin >> midterm >> finalterm;

//	cout << "input all your homework score [followed by EOF] : ";

//	vector<double> homeworks;

//	read_hw(cin, homeworks);


	try {

		for(vector<Student_info>::size_type i = 0; i!=students.size(); ++i)
		{
			streamsize ss = cout.precision();

//			cout << "Your final score : " << setprecision(3) 
//				 << grade(midterm, finalterm, homeworks) << setprecision(ss) << endl;
//			cout << students[i].name << " : " << setprecision(3)
			cout << students[i].name << string(maxLen - students[i].name.size(), ' ') 
				 << " : " << setprecision(3)
	 			 << grade(students[i])  << setprecision(ss) << endl;
		}
	} catch (const domain_error& e) {
		cerr << endl << e.what() << endl;		// what() : 지정해둔 에러메세지 출력
		return 1;
	}

	return 0;
}
