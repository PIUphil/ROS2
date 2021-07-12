//
// Created by phil on 21. 7. 12..
//

#ifndef VEC_VEC_H
#define VEC_VEC_H

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

    size_type size() const;
    reference_type operator[](int index);
    const_reference_type operator[](int index) const;

    iterator begin() { return this->data_; }        // 클래스 안에서 함수 정의 - 인라인함수
    iterator end() { return this->limit_; }
    const_iterator cbegin() const { return this->data_; }
    const_iterator cend() const { return this->limit_; }


private:
//    T* data_;
//    T* limit_;
    iterator data_;
    iterator limit_;
};


template <typename T>
Vec<T>::Vec()
{}

template <typename T>
Vec<T>::Vec(size_type size, const_reference_type val)
{}

template <typename T>
Vec<T>::Vec(const_iterator begin, const_iterator end)
{}

template <typename T>
Vec<T>::Vec(const Vec<T>& rhs)
{}

template <typename T>
Vec<T>::~Vec()
{}




template <typename T>
typename Vec<T>::size_type Vec<T>::size() const
{
    return this->limit_ - this->data_;
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





#endif //VEC_VEC_H
