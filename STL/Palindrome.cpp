/*
[과제2] 입력받은 단어가 회문인지 체크하는 프로그램
	   ex) 회문 : madam, civic
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


bool isPalindrome(const string& s)            // palindrome, 팰린드롬 = 회문
{
    string::size_type j = s.size()-1;

    for(string::size_type i=0 ; i!=s.size()/2 ; ++i,--j)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}



int main() {

    string str;

    while (cin >> str)
        //cout << str << " : " << isPalindrome(str) << endl;
        isPalindrome(str) ? cout<<"회문o"<<endl : cout<<"회문x"<<endl;

    return 0;
}
