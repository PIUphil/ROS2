#ifndef STR_STR_H
#define STR_STR_H

#include <algorithm>
#include <iterator>
#include <iostream>

#include "Vec.h"
#include "Handle.h"


class Str {
friend std::istream& operator>>(std::istream& in, Str& rhs);
friend std::ostream& operator<<(std::ostream& out, const Str& rhs);     // 전역함수

public:
typedef Vec<char>::size_type size_type;
typedef Vec<char>::iterator iterator;
typedef Vec<char>::const_iterator const_iterator;

    Str();
    Str(const char *s);
    Str(size_type n, char c);

    template <typename In>
    //Str(const_iterator begin, const_iterator end);
    Str(In begin, In end);

    //Str(const Str& rhs);          // 컴파일러가 제공하는거 그냥 사용하면 됨.. 생략가능
    //~Str();

    iterator begin() { return data_->begin(); }
    iterator end() { return data_->end(); }

    const_iterator cbegin() const { return data_->cbegin(); }
    const_iterator cend() const { return data_->cend(); }


    //Str& operator=(const Str& rhs);           // 묵시적호출

    Str& operator+=(const Str& rhs);

    bool operator==(const Str& rhs) const;
    // !=, >, <, >=, <=


    const Str operator+(const Str& rhs) const;


    const char *c_str() const;

    const_iterator data() const;
    size_type copy(char *des, size_type n, size_type pos = 0);

    template <typename In>
    void insert(iterator des, In begin, In end);


    size_type size() const;

    char& operator[](int index);
    const char& operator[](int index) const;


private:
    //Vec<char> data_;

    Handle<Vec<char> > data_;       // 메모리 공간 절약,,?     // Handle 이 shared_ptr처럼 작동함

    mutable char *str_;             // const가 붙으면 read only 되는데, 값을 바꿔야함;; => mutable 돌연변이
};


template <typename In>
//Str::Str(In begin, In end)
//    : data_(), str_(0)
//{
//    std::copy(begin, end, std::back_inserter(*data_));
//}
Str::Str(In begin, In end)
    : data_(new Vec<char>()), str_(0)
{
    std::copy(begin, end, std::back_inserter(*data_));
}


template <typename In>
void Str::insert(iterator des, In begin, In end)
{
    Vec<char> tmp(des, this->data_->cend());
    this->data_->erase(des, this->data_->end());
    std::copy(begin, end, std::back_inserter(*(this->data_)));
    std::copy(tmp.cbegin(), tmp.cend(), std::back_inserter(*(this->data_)));
}


#endif //STR_STR_H
