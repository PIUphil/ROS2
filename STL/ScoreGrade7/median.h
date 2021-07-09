#ifndef MEDIAN_H
#define MEDIAN_H

#include <vector>
#include <algorithm>
#include <stdexcept>

/*
using std::vector;
using std::sort;
using std::domain_error;


//double median(std::vector<double> vec);


double median(vector<double> vec)
{
    if (vec.size()==0) {
        // throw 0;
        throw domain_error("vector is empty");
    }

    sort(vec.begin(), vec.end());
    vector<double>::size_type mid = vec.size() / 2;
    double median = (vec.size() % 2) ? vec[mid] : (vec[mid] + vec[mid-1]) / 2;

    return median;
}
*/

template <typename T>
T median(std::vector<T> vec)
{
    if (vec.size()==0) {
        // throw 0;
        throw std::domain_error("vector is empty");
    }

    std::sort(vec.begin(), vec.end());

    typename std::vector<T>::size_type mid = vec.size() / 2;

    T median = (vec.size() % 2) ? vec[mid] : (vec[mid] + vec[mid-1]) / 2;

    return median;
}

#endif
