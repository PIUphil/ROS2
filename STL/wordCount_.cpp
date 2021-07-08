#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;


int main()
{
    map<string, int> wordCount;         // value가 비어있으면 int값의 디폴트인 0이 들어감

    string s;
    while (cin >> s)
    {
        ++wordCount[s];
    }

    for(auto iter=wordCount.cbegin() ; iter!=wordCount.cend() ; ++iter)
        cout << iter->first << " : " << iter->second << endl;   // first : 키값, second : value값


    return 0;
}
