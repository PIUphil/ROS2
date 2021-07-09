#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;


int main()
{

    const char rank[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

    map<char, vector<string> > rankName;

    while (cin)
    {
        string name;
        cin >> name;

        double score;
        cin >> score;


        rankName[rank[static_cast<int>(score)/10]].push_back(name);


        // cout << name << " : " << score << endl;
    }

    for(auto iter=rankName.cbegin() ; iter!=rankName.cend() ; ++iter)
    {
        cout << iter->first << " : ";

        for(auto iter2=iter->second.cbegin() ; iter2!=iter->second.cend() ; ++iter2)
            cout << *iter2 << ((iter2+1 != iter->second.cend()) ? ", " : "");   // 맨마지막은 ','표시안함

        cout << endl;
    }
    return 0;
}
