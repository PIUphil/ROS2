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
using std::sort;
using std::domain_error;


//double median(const vector<double>& vec)   
// 	클래스타입의 인자를 넘길 때,,, 레퍼런스를 사용,, // 밸류로 넘기면 복사생성자 생성되고 소멸자호출되고 오버헤드 생길수있어서,,?
//{
//	vector<double> tmp = vec;
//	sort(tmp.begin(), tmp.end());	
//}

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



int main()
{
	cout << "input your name : ";
	string name;
	cin >> name;

	cout << "input your midterm final homework : ";
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	cout << "input all your homework score [followed by EOF] : ";
//	int count = 0;
//	int sum = 0;

	vector<double> homeworks;

	read_hw(cin, homeworks);

//	vector<double>::size_type size = homeworks.size();

// 	auto size = homeworks.size();
//	if (size == 0) {
//		cout << endl << "you must input your scores." "please try again" << endl;
//		
//		return 1;
//	}	


	try {
		streamsize ss = cout.precision();

		cout << "Your final score : " << setprecision(3) 
//			 << 0.2*midterm + 0.4*finalterm + 0.4*median << setprecision(ss) << endl;
			 << grade(midterm, finalterm, homeworks) << setprecision(ss) << endl;
	} catch (const domain_error& e) {
		cerr << endl << "you must enter your homework score" << endl;		// cerr, clog
		// cerr : 표준에러출력장치(콘솔로 출력됨) - 내부적으로 버퍼를 안쓰고 출력함.
		// clog : log메세지 출력. - 로그파일로 redirect 출력가능
		return 1;		// 메인이 비정상적으로 종료,,
	}

	return 0;
}
