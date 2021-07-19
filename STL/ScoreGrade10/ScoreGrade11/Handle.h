#ifndef SCOREGRADE11_HANDLE_H
#define SCOREGRADE11_HANDLE_H

#include <stdexcept>


template <typename T>
class Handle {
public:
    Handle();
    Handle(T* ptr);
    Handle(const Handle<T>& rhs);
    ~Handle();
    Handle<T>& operator=(const Handle<T>& rhs);

    operator bool() const;   // 포인터 타입이 불타입으로 바뀜 - 조건식에서 사용하려고,,
    T& operator*() const;
    T* operator->() const;

private:
    T* ptr_;
    std::size_t *refPtr_;
};


template <typename T>
Handle<T>::Handle()
    :ptr_(0), refPtr_(new std::size_t(1))   // 힙상에 객체를 만들고 주소를 줌,,?
{}

template <typename T>
Handle<T>::Handle(T* ptr)
    :ptr_(ptr), refPtr_(new std::size_t(1))
{}

template <typename T>
Handle<T>::Handle(const Handle<T>& rhs)
    :ptr_(rhs.ptr_), refPtr_(rhs.refPtr_)
{
    //this->ptr_ = (rhs.ptr_) ? rhs.ptr_->clone() : 0;
    ++*refPtr_;
}

template <typename T>
Handle<T>::~Handle()
{
    if(--*refPtr_ == 0)
    {
        delete ptr_;
        delete refPtr_;
    }
}


template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs)
{
    if (this!=&rhs)
    {
        if(--*refPtr_ == 0)
        {
            delete ptr_;
            delete refPtr_;
        }

        //delete this->ptr_;

        //this->ptr_ = (rhs.ptr_) ? rhs.ptr_->clone() : 0;

        ptr_ = rhs.ptr_;
        refPtr_ = rhs.refPtr_;
        ++*refPtr_;
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


#endif //SCOREGRADE11_HANDLE_H
