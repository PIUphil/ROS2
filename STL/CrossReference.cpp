#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::find_if;


bool is_space(char c)
{
    return isspace(c);
}

bool is_not_space(char c)
{
    return !isspace(c);
}


vector<string> split(const string& str)
{
    vector<string> result;

    string::const_iterator iter1 = str.cbegin();
    //auto iter1 = str.cbegin();
    while(iter1 != str.cend())
    {
        iter1 = find_if(iter1, str.cend(), is_not_space);

        auto iter2 = find_if(iter1, str.cend(), is_space);

        if(iter1 != iter2)
        {
            result.push_back(string(iter1, iter2));
            iter1 = iter2;
        }
    }

    return result;
}


int main()
{
    map<string, vector<int> > crossRef;

    int line = 1;
    string s;

    while(getline(cin, s))
    {
        vector<string> words = split(s);
        for (auto iter=words.cbegin() ; iter!=words.cend() ; ++iter)
            crossRef[*iter].push_back(line);

        ++line;
    }

    //for(map<string, vector<int> >::const_iterator iter = crossRef.cbegin(); iter!=crossRef.end() ; ++iter)
    for(auto iter = crossRef.cbegin() ; iter!=crossRef.cend() ; ++iter)
    {
        cout << iter->first << " : ";

        for(auto iter2 = iter->second.cbegin() ; iter2!=iter->second.cend() ; ++iter2)
            cout << *iter2 << ", ";

        cout << endl;
    }

    return 0;
}
