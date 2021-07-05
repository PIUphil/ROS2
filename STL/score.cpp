#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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

	cout << "Your final score : " << 0.2*midterm + 0.4*finalterm + 0.4*sum/count << endl;

	return 0;
}
