#ifndef SCOREGRADE10_HANDLE_H
#define SCOREGRADE10_HANDLE_H

#include <stdexcept>


template <typename T>
class Handle {
public:
    Handle();
    Handle(const T* ptr);
    Handle(const Handle<T>& rhs);
    ~Handle();
    Handle<T>& operator=(const Handle<T>& rhs);

    operator bool() const;   // 포인터 타입이 불타입으로 바뀜 - 조건식에서 사용하려고,,
    T& operator*() const;
    T* operator->() const;

private:
    T* ptr_;
};


template <typename T>
Handle<T>::Handle()
    :ptr_(0)
{}

template <typename T>
Handle<T>::Handle(const T* ptr)
    :ptr_(const_cast<T *>(ptr))
{}

template <typename T>
Handle<T>::Handle(const Handle<T>& rhs)
{
    this->ptr_ = (rhs.ptr_) ? rhs.ptr_->clone() : 0;

//    if(rhs.ptr_)
//        this->ptr_ = rhs.ptr_->clone();
//    else
//        this->ptr_ = 0;
}

template <typename T>
Handle<T>::~Handle()
{
    delete this->ptr_;
}


template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs)
{
    if (this!=&rhs)
    {
        delete this->ptr_;

        this->ptr_ = (rhs.ptr_) ? rhs.ptr_->clone() : 0;
    }

    return *this;
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


#endif //SCOREGRADE10_HANDLE_H
