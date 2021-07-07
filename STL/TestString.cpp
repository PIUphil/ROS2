#include <iostream>
#include <vector>
#include <string>
#include <cctype>       // isspace 사용하기위해
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;


vector<string> split(const string& str)
{
    vector<string> result;

    vector<string>::size_type i = 0;
    while (i!=str.size())
    {
        while(i!=str.size() && isspace(str[i]))     // 여백 넘어감
            ++i;

        auto j = i;         // vector<string>::size_type j
        while(j!=str.size() && !isspace(str[j]))
            ++j;

        if(i!=j)            // 단어를 찾아냄
        {
            result.push_back(str.substr(i, j - i));    // 문자열 뽑아서 저장    // (시작위치,개수)
            i = j;
        }
    }

    return result;
}


string::size_type width(const vector<string>& words)
{
    string::size_type maxLen = 0;
    for(auto iter=words.cbegin() ; iter!=words.cend() ; ++iter)
    {
//        if(maxLen < iter->size())
//            maxLen = iter->size();
        maxLen = max(maxLen, iter->size());
    }

    return maxLen;
}


vector<string> frame(const vector<string>& words)
{
    string::size_type maxLen = width(words);
    vector<string> result;

    string boarder(maxLen+4, '*');
    result.push_back(boarder);

    for(auto iter=words.cbegin() ; iter!=words.cend() ; ++iter)
    {
        string str = "* " + *iter + string(maxLen-iter->size(), ' ') + " *";
        result.push_back(str);
    }

    result.push_back(boarder);

    return result;
}


int main()
{

    //string str = "knocking on the heaven's door";
    string str;
    cout << "문장입력 : ";

    while (getline(cin, str))
    {
        vector<string> words = split(str);
//        for (vector<string>::const_iterator iter=words.cbegin() ; iter!=words.cend() ; ++iter)
//        for (auto iter=words.cbegin() ; iter!=words.cend() ; ++iter)
//            cout << *iter << endl;

        vector<string> frameWords = frame(words);
        for (auto iter=frameWords.cbegin() ; iter!=frameWords.cend() ; ++iter)
            cout << *iter << endl;

    }

    return 0;
}
