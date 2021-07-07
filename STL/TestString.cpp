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


vector<string> vcat(const vector<string>& v1, const vector<string>& v2)     // 문장 합치기
{
    vector<string> result;

//    for(auto iter=v1.cbegin() ; iter!=v1.cend() ; ++iter)
//        result.push_back(*iter);

//    for(auto iter=v2.cbegin() ; iter!=v2.cend() ; ++iter)
//        result.push_back(*iter);

    result.insert(result.end(), v1.cbegin(), v1.cend());
    result.insert(result.end(), v2.cbegin(), v2.cend());        //v2의 처음부터 끝까지를 end뒤에 추가

    return result;
}


vector<string> hcat(const vector<string>& v1, const vector<string>& v2)
{
    string::size_type width1 = width(v1) + 1;       // +1 : 여백

    vector<string> result;
    //vector<string>::const_iterator i = 0;
    auto iter1 = v1.cbegin();
    auto iter2 = v2.cbegin();

    while (iter1!=v1.cend() || iter2!=v2.cend()) {
        string str;

        if (iter1 != v1.cend())
        {
            str += *iter1;
            ++iter1;
        }

        str += string(width1-str.size(), ' ');

        if(iter1 != v2.cend())
        {
            str += *iter2;
            ++iter2;
        }

        result.push_back(str);
    }

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
//        for (auto iter=frameWords.cbegin() ; iter!=frameWords.cend() ; ++iter)
//            cout << *iter << endl;


//        vector<string> verticalWords = vcat(words, frameWords);
//
//        for(auto iter=verticalWords.cbegin() ; iter!=verticalWords.cend() ; ++iter)
//            cout << *iter << endl;


        vector<string> horiWords = hcat(words, frameWords);
        for(auto iter=horiWords.cbegin() ; iter!=horiWords.cend() ; ++iter)
            cout << *iter << endl;


    }

    return 0;
}
