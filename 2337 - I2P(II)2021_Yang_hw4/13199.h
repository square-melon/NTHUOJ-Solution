#ifndef I2P2_DEF_H
#define I2P2_DEF_H
#include <iostream>
#include <cstdint>

namespace oj {

using size_type = std::size_t;
using value_type = int64_t;
using pointer = value_type *;
using const_pointer = const value_type *;
using reference = value_type &;
using const_reference = const value_type &;
	
class Vector {
private:
    value_type **arr_;
    size_type size_, cap_;
public:
    ~Vector();
    Vector();
    Vector(const Vector &rhs);
    Vector &operator=(const Vector &rhs);
    reference front();
    reference back();
    reference operator[](size_type pos);
	const_reference operator[](size_type pos) const;
    size_type capacity() const;
    size_type size() const;
    void clear();
    bool empty() const;
    void erase(size_type pos);
    void insert(size_type pos, size_type cnt, const_reference val);
    void pop_back();
    void pop_front();
    void push_back(const_reference val);
    void push_front(const_reference val);
    void reserve(size_type new_capacity);
    void shrink_to_fit();
};

}

void* operator new(std::size_t);
void* operator new[](std::size_t); 
void operator delete(void *) noexcept;
void operator delete[](void *) noexcept;

#endif

