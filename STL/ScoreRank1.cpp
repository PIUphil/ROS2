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

    char rank[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

    map<char, int> rankCount;

    while (cin)
    {
        string name;
        cin >> name;

        double score;
        cin >> score;

        /*
        if(score >= 90)
            ++rankCount['A'];
        else if(score >= 80)
            ++rankCount['B'];
        else if(score >= 70)
            ++rankCount['C'];
        else if(score >= 60)
            ++rankCount['D'];
        else
            ++rankCount['F'];
        */

        /*
        switch(static_cast<int>(score)/10)
        {
        case 10: case 9:
            ++rankCount['A'];
            break;
        case 8:
            ++rankCount['B'];
            break;
        case 7:
            ++rankCount['C'];
            break;
        case 6:
            ++rankCount['D'];
            break;
        default:
            ++rankCount['F'];
            break;
        }
        */

        ++rankCount[rank[static_cast<int>(score)/10]];


        cout << name << " : " << score << endl;
    }

    for(auto iter=rankCount.cbegin() ; iter!=rankCount.cend() ; ++iter)
        cout << iter->first << " : " << iter->second << endl;

    return 0;
}
