#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
bool isPalindrome(const string& s)            // palindrome, 팰린드롬 = 회문
{
    string::size_type j = s.size()-1;

    for(string::size_type i=0 ; i!=s.size()/2 ; ++i,--j)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}*/

bool isPalindrome(const string& s)
{
    return equal(s.cbegin(), s.cend(), s.crbegin());        // r : reverse -> reverse_iterator
}


int main() {

    string str;

    while (cin >> str)
        cout << "단어 입력 : ";
        //cout << str << " : " << isPalindrome(str) << endl;
        isPalindrome(str) ? cout<<"회문o"<<endl : cout<<"회문x"<<endl;

    return 0;
}
