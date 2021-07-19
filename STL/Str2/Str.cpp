//
// Created by phil on 21. 7. 12..
//
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cctype>           // isspace
#include "Str.h"


std::istream& operator>>(std::istream& in, Str& rhs)
{
    rhs.data_->clear();
    char c;

    while (in.get(c) && isspace(c))
        ;                                   // 문장 앞에 여백(화이트 스페이스)이 들어가는것 무시

    do
    {
        rhs.data_->push_back(c);
    } while (in.get(c) && !isspace(c));

    if (in)
        in.unget();

    return in;
}


std::ostream& operator<<(std::ostream& out, const Str& rhs)
{
    std::copy(rhs.data_->cbegin(), rhs.data_->cend(), std::ostream_iterator<char>(out));
    return out;
}


Str::Str()                      // has-a 관계
     : data_(new Vec<char>()), str_(0)         // data_는 생략가능
{}

Str::Str(const char *s)
//    : data_(s, s+strlen(s)) , str_(0)     // +1을 하면 \0까지 들어감
    : data_(new Vec<char>()) , str_(0)
{
    std::copy(s, s+strlen(s), std::back_inserter(*(this->data_)));
}

Str::Str(size_type n, char c)
//    : data_(n, c), str_(0)
    : data_(new Vec<char>()), str_(0)
{
    for(std::string::size_type i=0 ; i<=n ; ++i)
    {
        this->data_->push_back(c);
    }
}

/*
Str::Str(const Str& rhs)             // 생략가능. 묵시적호출
    : data_(rhs.data_), str_(0)     // str_(rhs.str_)을 하면 shallow_copy가 됨..
{}

Str::~Str()
{
//    if (this->str_)
//        delete [] this->str_;
}



Str& Str::operator=(const Str &rhs)
{
    this->data_ = rhs.data_;
    this->str_ = 0;
    return *this;
}*/                         // shallow_copy 사용하므로 필요없음,,?



Str& Str::operator+=(const Str& rhs)
{
    this->data_.make_unique();          // 복사본 만듦

    std::copy(rhs.data_->cbegin(), rhs.data_->cend(), std::back_inserter(*data_));
    return *this;
}


bool Str::operator==(const Str &rhs) const
{
    return *(this->data_) == *(rhs.data_);
}


const Str Str::operator+(const Str& rhs) const
{
    Str result(*this);              // 복제       // Str result = *this;
    result += rhs;
    return result;
}


const char* Str::c_str() const
{
    //return this->data_->cbegin();    // \0이 벡터에 들어있지 않음.    // 포인터필요(멤버변수), new/delete -> delete 소멸자에서

    if(this->str_==0)
    {
        this->str_ = new char[this->data_->size() + 1];
        std::copy(this->data_->cbegin(), this->data_->cend(), this->str_);
        this->str_[this->data_->size()] = '\0';          // NUL (L 하나)  // NULL = 포인터가 0일 때 사용

        return this->str_;
    }

    return this->str_;
}


Str::const_iterator Str::data() const
{
    return this->data_->cbegin();
}


Str::size_type Str::copy(char *des, size_type n, size_type pos)
{
    std::copy(this->data_->cbegin()+pos, this->data_->cbegin()+pos+n-1, des);
    des[n-1] = '\0';          // 출력할 때 \0이 없으면 끝을 모르므로 출력이 안됨 -> \0을 넣어줘야함

    return n;
}


Str::size_type Str::size() const
{
    return this->data_->size();
}

char& Str::operator[](int index)
{
    return (*this->data_)[index];
}

const char& Str::operator[](int index) const
{
    return (*this->data_)[index];
}

