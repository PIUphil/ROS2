#ifndef SCOREGRADE9_MEDIAN_H
#define SCOREGRADE9_MEDIAN_H

#include <vector>
#include <algorithm>
#include <stdexcept>


template <typename T>
T median(const std::vector<T>& vec)
{
    if(vec.empty())
        throw std::domain_error("vector is empty");

    std::vector<T> tmp = vec;
    std::sort(tmp.begin(), tmp.end());

    typename std::vector<T>::size_type size = tmp.size();        // auto 가능
    auto mid = size / 2;
    if(size%2)
        return vec[mid];
    else
        return (vec[mid] + vec[mid-1]) / 2;

}

#endif //SCOREGRADE9_MEDIAN_H



