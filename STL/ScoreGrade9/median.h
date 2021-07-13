#ifndef SCOREGRADE9_MEDIAN_H
#define SCOREGRADE9_MEDIAN_H

#include <vector>
#include <algorithm>


template <typename T>
T median(const std::vector<T>& vec)
{
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



