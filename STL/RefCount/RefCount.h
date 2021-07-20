#ifndef REFCOUNT_REFCOUNT_H
#define REFCOUNT_REFCOUNT_H

#include <cstddef>



class RefCount {
public:
    RefCount();
    RefCount(const RefCount& rhs);
    ~RefCount();

    RefCount& operator=(const RefCount& rhs);       // not use

    std::size_t count() const;

    void clone();

//    std::size_t& operator++();               // 앞에 붙는거
//    std::size_t operator++(int );            // 뒤에 붙는거
//
//    std::size_t& operator--();
//    std::size_t operator--(int );


private:
    std::size_t *pCount_;



};


#endif //REFCOUNT_REFCOUNT_H
