//
// Created by phil on 21. 7. 12..
//

#ifndef VEC_VEC_H
#define VEC_VEC_H

#include <memory>           // allocator
#include <algorithm>        // max


template <typename T>
class Vec {
public:

    typedef unsigned int size_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T value_type;
    typedef T& reference_type;
    typedef const T& const_reference_type;
    typedef std::ptrdiff_t difference_type;         // 포인터간 차이


    Vec();
    //explicit Vec(int size);
    //explicit Vec(int size, const T& val = T())
    explicit Vec(size_type size, const_reference_type val = T());
    //Vec(const T* begin, const T* end);
    Vec(const_iterator begin, const_iterator end);
    Vec(const Vec<T>& rhs);     // 복사생성자
    ~Vec();

    const Vec<T>& operator=(const Vec<T>& rhs);
    bool operator==(const Vec<T>& rhs) const;

    size_type size() const;
    reference_type operator[](int index);
    const_reference_type operator[](int index) const;

    iterator begin() { return this->data_; }        // 클래스 안에서 함수 정의 - 인라인함수
    iterator end() { return this->avail_; }
    const_iterator cbegin() const { return this->data_; }
    const_iterator cend() const { return this->avail_; }

    void push_back(const_reference_type val);


    iterator erase(iterator iter);
    iterator erase(iterator begin, iterator end);

    void clear();


private:
    std::allocator<T> alloc_;

    void create();
    void create(size_type size, const_reference_type val);
    void create(const_iterator begin, const_iterator end);
    void uncreate();

    void grow();                                            //멤버함수를 구현하기위한 도구함수들 -> private쪽으로,,
    void unchecked_append(const_reference_type val);


//    T* data_;
//    T* limit_;
    iterator data_;         // 데이터 처음 위치
    iterator avail_;        // 데이터의 마지막 위치 +1
    iterator limit_;        // 데이터 할당공간의 마지막 위치 +1
};


template <typename T>
void Vec<T>::create()
{
    this->data_ = this->avail_ = this->limit_ = 0;
}

template <typename T>
void Vec<T>::create(size_type size, const_reference_type val)
{
    this->data_ = this->alloc_.allocate(size);
    this->avail_ = this->data_ + size;
    this->limit_ = this->avail_;
    std::uninitialized_fill(this->data_, this->avail_, val);        // 값 채워줌
}

template <typename T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
    this->data_ = this->alloc_.allocate(end-begin);
    this->avail_ = this->data_ + (end-begin);
    this->limit_ = this->avail_;
    std::uninitialized_copy(begin, end, this->data_);           // 범위를 주고 집어넣는 시작위치 줌
}

template <typename T>
void Vec<T>::uncreate()
{
    if(this->data_)
    {
        iterator iter = this->avail_;
        while(iter != this->data_)
        {
            --iter;
            this->alloc_.destroy(iter);
        }

        this->alloc_.deallocate(this->data_, this->limit_ - this->data_);
    }

    this->data_ = this->avail_ = this->limit_ = 0;
}


template <typename T>
void Vec<T>::grow()                             // 사이즈 2배로 늘리기
{
    size_type new_size = std::max(2*(this->limit_-this->data_), static_cast<difference_type>(1));     // 비어있으면 그냥 1로 줌

//    if(this->data_ ==0)
//        new_size = 1;
//    else
//        new_size = 2*(this->limit_-this->data_);

    iterator new_data = this->alloc_.allocate(new_size);
//    iterator new_avail = new_data + new_size;
//    std::uninitialized_copy(this->data_, this->avail_, new_data);           // 마지막 위치를 리턴해줌
    iterator new_avail
            = std::uninitialized_copy(this->data_, this->avail_, new_data);

    this->uncreate();
    this->data_ = new_data;
    this->avail_ = new_avail;
    this->limit_ = this->data_ + new_size;
}

template <typename T>
void Vec<T>::unchecked_append(const_reference_type val)
{
    this->alloc_.construct(this->avail_, val);
    ++this->avail_;
}



template <typename T>
Vec<T>::Vec()
{
    this->create();
}

template <typename T>
Vec<T>::Vec(size_type size, const_reference_type val)
{
    this->create(size, val);
}

template <typename T>
Vec<T>::Vec(const_iterator begin, const_iterator end)
{
    this->create(begin, end);
}

template <typename T>
Vec<T>::Vec(const Vec<T>& rhs)
{
    this->create(rhs.data_, rhs.avail_);
}


template <typename T>
Vec<T>::~Vec()
{
    this->uncreate();
}


template <typename T>
const Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    if (this != &rhs) {
        this->uncreate();
        this->create(rhs.data_, rhs.avail_);
    }

    return *this;
}

template <typename T>
bool Vec<T>::operator==(const Vec<T>& rhs) const
{
    return std::equal(this->cbegin(), this->cend(), rhs.cbegin());
}


template <typename T>
typename Vec<T>::size_type Vec<T>::size() const
{
    return this->avail_ - this->data_;
}

template <typename T>
typename Vec<T>::reference_type Vec<T>::operator[](int index)
{
    return this->data_[index];
}

template <typename T>
typename Vec<T>::const_reference_type Vec<T>::operator[](int index) const
{
    return this->data_[index];
}

template <typename T>
void Vec<T>::push_back(Vec<T>::const_reference_type val)
{
    if (this->avail_ == this->limit_)
        this->grow();                   // 칸 없으면 두배로 늘림

    this->unchecked_append(val);
}


template <typename T>
typename Vec<T>::iterator Vec<T>::erase(iterator iter)
{
    std::copy(iter+1, this->avail_, iter);
    this->alloc_.destroy(this->avail_);
    --this->avail_;

    return iter+1;
}


template <typename T>
typename Vec<T>::iterator Vec<T>::erase(iterator begin, iterator end)
{
    iterator new_avail_;
    if(end == this->avail_)
        new_avail_ = begin;
    else
        new_avail_ = std::copy(end+1, this->avail_, begin);

    iterator iter = this->avail_;
    while (iter != new_avail_)
    {
        --iter;
        this->alloc_.destroy(iter);
    }

    this->avail_ = new_avail_;

    return end+1;
}


template <typename T>
void Vec<T>::clear()
{
    this->uncreate();
}



#endif //VEC_VEC_H
