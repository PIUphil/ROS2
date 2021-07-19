#include <memory>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>


#include "Handle.h"
#include "Core.h"
#include "Grad.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;
using std::string;
using std::domain_error;
using std::setprecision;

int main() {
    /*
    //std::shared_ptr<std::string> str = std::make_shared<std::string>();
    std::shared_ptr<Core> str = std::make_shared<Grad>();

    Handle<Core> handle(new Grad);          // Core쪽에서 delete됨,,  // make_shared
    */

    vector<Handle<Core> > students;
    string::size_type maxLen = 0;

    char ch;
    while (cin >> ch)
    {
        Handle<Core> handle;

        if (ch == 'U')
        {
            handle = new Core;
        }
        else if (ch == 'G')
        {
            handle = new Grad;
        }

        handle->read(cin);
        students.push_back(handle);

        maxLen = max(maxLen, handle->name().size());
    }

    sort(students.begin(), students.end(), compare_handle);

    //for(auto handle : students)
    for(const Handle<Core> handle : students)
    {
        cout << handle->name() << string(maxLen-handle->name().size(), ' ') << " : ";

        try
        {
            double finalScore = handle->grade();

            std::streamsize ss = cout.precision();

            //cout << setprecision(3) << handle->grade() << setprecision(ss) << endl;
            cout << setprecision(3) << finalScore << setprecision(ss) << endl;
        }
        catch(domain_error& e)
        {
            std::cerr << e.what() << endl;
        }
    }

    // 자동으로 delete됨..

    return 0;
}