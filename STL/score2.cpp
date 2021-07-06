#include <iostream>
#include <ios>
#include <iomanip>		// manipulator 조력자, 조작자
#include <string>
#include <vector>		// 벡터 ; 가변길이 배열 - 가득찬 후에 넣으려고하면(push_back) 크기가 2배씩 늘어남..
#include <algorithm>	// sort사용하기위해

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using std::streamsize;
using std::sort;

//using namespace std;

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
	double hw;
	while (cin >> hw) {
		homeworks.push_back(hw);
	}

	vector<double>::size_type size = homeworks.size();
	// auto size = homeworks.size();

	if (size == 0) {
		cout << endl << "you must input your scores." "please try again" << endl;
		
		return 1;
	}	

	sort(homeworks.begin(), homeworks.end());		// end()는 맨 마지막의 다음위치를 가리킴	// iterate 타입
	
	vector<double>::size_type mid = homeworks.size() / 2;
//	double median;
	double median = (size%2 /* !=0 */) ? homeworks[mid] : (homeworks[mid] + homeworks[mid-1]) / 2;

//	if (size%2 != 0) {
//		median = homeworks[mid];
//	} else {
//		median = (homeworks[mid] + homeworks[mid-1]) / 2;
//	}



	streamsize ss = cout.precision();
	// cout << "Your final score : " << 0.2*midterm + 0.4*finalterm + 0.4*sum/count << endl;
	cout << "Your final score : " << setprecision(3) 
		 << 0.2*midterm + 0.4*finalterm + 0.4*median << setprecision(ss) << endl;

	// setprecision(3) : 숫자 3개만 출력함 -> 정수2자리, 소수1자리 출력됨.. -> 정수1, 소수2자리 출력될수도 있음
	// setprecision(ss) : 원래 상태로 복구시킴 // streamsize

	return 0;
}
