#include <iostream>
#include <ios>
#include <iomanip>		// manipulator 조력자, 조작자
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;

int main()
{
	cout << "input your name : ";
	string name;
	cin >> name;

	cout << "input your midterm final homework : ";
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	cout << "input all your homework score [followed by EOF] : ";
	int count = 0;
	int sum = 0;

	double hw;
	while (cin >> hw) {		// 입력받으면 True, 아니면 False
		++count;
		sum += hw;
	}
	
	streamsize ss = cout.precision();
	// cout << "Your final score : " << 0.2*midterm + 0.4*finalterm + 0.4*sum/count << endl;
	cout << "Your final score : " << setprecision(3) 
		 << 0.2*midterm + 0.4*finalterm + 0.4*sum/count << setprecision(ss) << endl;

	// setprecision(3) : 숫자 3개만 출력함 -> 정수2자리, 소수1자리 출력됨.. -> 정수1, 소수2자리 출력될수도 있음
	// setprecision(ss) : 원래 상태로 복구시킴 // streamsize

	return 0;
}
