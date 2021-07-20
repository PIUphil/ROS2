#ifndef SCOREGRADE11_HANDLE_H
#define SCOREGRADE11_HANDLE_H

#include <stdexcept>

#include "RefCount.h"


template <typename T>
T* clone(const T *ptr)          // template specialization  - 구체적인 타입에 대해서는 따로 구현,, cpp로 작성
{
    return ptr->clone();
}

template <typename T>
class Handle {
public:
    Handle();
    Handle(T* ptr);
    Handle(const Handle<T>& rhs);
    ~Handle();
    Handle<T>& operator=(const Handle<T>& rhs);

    void make_unique();

    operator bool() const;   // 포인터 타입이 불타입으로 바뀜 - 조건식에서 사용하려고,,
    T& operator*() const;
    T* operator->() const;

private:
    T* ptr_;
    //std::size_t *refPtr_;
    RefCount count_;
};


template <typename T>
Handle<T>::Handle()
    :ptr_(0), count_()//refPtr_(new std::size_t(1))   // 힙상에 객체를 만들고 주소를 줌,,?
{}

template <typename T>
Handle<T>::Handle(T* ptr)
    :ptr_(ptr), count_()//refPtr_(new std::size_t(1))
{}

template <typename T>
Handle<T>::Handle(const Handle<T>& rhs)
    :ptr_(rhs.ptr_), count_(rhs.count_)//refPtr_(rhs.refPtr_)
{
    //++*refPtr_;
}

template <typename T>
Handle<T>::~Handle()
{
    // --*refPtr_;

    //if(--*refPtr_ == 0)
    if(count_.count() == 1)
    {
        delete ptr_;
        //delete refPtr_;
    }
}


template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs)
{
    if (this!=&rhs)
    {
        //if(--*refPtr_ == 0)
        if(count_.count() == 1)
        {
            delete ptr_;
            count_.~RefCount();
            //delete refPtr_;
        }

        ptr_ = rhs.ptr_;
        //refPtr_ = rhs.refPtr_;
        //++*refPtr_;
        count_ = rhs.count_;
    }

    return *this;
}

template <typename T>
void Handle<T>::make_unique()
{
    //if(refPtr_ != 1)
    if(count_.count() != 1)
    {
        count_.clone();
        //--*refPtr_;
        //refPtr_ = new std::size_t(1);

        //ptr_ = (ptr_) ? this->ptr_->clone() : 0;
        if(ptr_)
            //ptr_ = this->ptr_->clone();
            ptr_ = ::clone(ptr_);
    }
}

template <typename T>
Handle<T>::operator bool() const
{
    return static_cast<bool>(this->ptr_);
}

template <typename T>
T& Handle<T>::operator*() const
{
    if (this->ptr_)
        return *this->ptr_;
    else
        throw std::runtime_error("unbound handle");
}

template <typename T>
T* Handle<T>::operator->() const
{
    if (this->ptr_)
        return this->ptr_;
    else
        throw std::runtime_error("unbound handle");
}


#endif //SCOREGRADE11_HANDLE_H
