/*
[과제1] 문자열을 입력받아서 (대문자가 포함된 단어),
	   (대문자가 포함되지 않은 단어)를 구분하여 출력.
*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


bool isBig(const string& str)
{
    for(string::size_type i=0; i!=str.size(); ++i)
        if(str[i]>='A' && str[i]<='Z')
            return false;

    return true;
}


vector<string> extract_big(vector<string>& words)
{
    vector<string> smallWords;
    for(auto iter = words.begin() ; iter!=words.end() ;)
    {
        if(isBig(*iter))
        {
            smallWords.push_back(*iter);
            iter = words.erase(iter);
        }
        else
            ++iter;
    }

    return smallWords;
}

int main()
{
    vector<string> words;
    string str;

    cout << "문장입력(끝나면 Ctrl+D) : ";

    while(cin >> str)
    {
        words.push_back(str);
    }

    vector<string> smallWords = words;
    vector<string> bigWords = extract_big(smallWords);

    cout << "all small char : " << endl;
    for(auto iter=smallWords.cbegin() ; iter!=smallWords.cend() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "not all small char : " << endl;
    for(auto iter=bigWords.cbegin() ; iter!=bigWords.cend() ; ++iter)
        cout << *iter << " ";
    cout << endl;


    return 0;
}
