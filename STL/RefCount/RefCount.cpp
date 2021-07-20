#include "RefCount.h"


// int i = 10;              // int i(10);
// unsigned int count(1);   // unsigned int *pCount = new unsigned int(1);


RefCount::RefCount()
    :pCount_(new std::size_t(1))
{}


RefCount::RefCount(const RefCount &rhs)
    :pCount_(rhs.pCount_)
{
    ++(*pCount_);
}


RefCount::~RefCount()
{
    if (--(*pCount_)==0)
        delete pCount_;
}

RefCount& RefCount::operator=(const RefCount &rhs)
{
    if(this != &rhs)
    {
        if(--(*pCount_)==0)
            delete pCount_;

        pCount_ = rhs.pCount_;
        ++(*pCount_);
    }

    return *this;
}

std::size_t RefCount::count() const
{
    return *pCount_;
}


void RefCount::clone()
{
    --(*pCount_);
    pCount_ = new std::size_t(1);
}

/*
std::size_t& RefCount::operator++()
{
    return ++(*pCount_);
}

std::size_t RefCount::operator++(int)
{
    std::size_t tmp(*pCount_);
    ++(*pCount_);
    return tmp;
}

std::size_t& RefCount::operator--()
{
    return --(*pCount_);
}

std::size_t RefCount::operator--(int)
{
    std::size_t tmp(*pCount_);
    --(*pCount_);
    return tmp;
}*/