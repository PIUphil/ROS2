#include <iostream>
#include <string>
// #include <string.h>
// #include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// const string str = "hello, world";

	string name;
	cout << "input your name : ";
	cin >> name;

	//const string greeting = "hello, world " + name;
	const string greeting = "hello, world" ", " + name;

	const int pad = 1;

	const int rows = 3 + 2*pad;
	string::size_type cols = greeting.size() + 2*pad + 2;


	for (int i = 0; i < rows; ++i) {
		string::size_type c = 0;
		
		while (c != cols) {
			if (i == pad+1 && c == pad+1) {	// 아래로 2번째, 오른쪽으로 2번째 (0,1,2)
				cout << greeting;
				c += greeting.size();
			} else{
				if (i==0 || i==rows-1 || c==0 || c==cols-1)
					cout << "*";
				else
					cout << " ";

				++c;
			}
		}

		cout << endl;
	}

	return 0;
}


/*
*********************
*                   *
* hello world, phil *
*                   *
*********************

class string {
public:
	typedef unsigned int size_type;

}


string::size_type 			// unsigned int  	// 스트링과 관련된 길이타입
*/




