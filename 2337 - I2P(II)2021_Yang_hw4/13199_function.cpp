#include "13199.h"

using namespace oj;

Vector::Vector() {
    size_ = 0;
    cap_ = 10000;
    arr_ = new value_type*[10000];
    for (int i = 0; i < cap_; i++) arr_[i] = new value_type(0);
}

Vector::~Vector() {
    for (int i = 0; i < cap_; i++) delete arr_[i];
    delete[] arr_;
}

Vector::Vector(const Vector &rhs) {
    cap_ = rhs.capacity();
    size_ = rhs.size();
    arr_ = new value_type*[cap_];
    for (int i = 0; i < cap_; i++) arr_[i] = new value_type(0);
    for (int i = 0; i < size_; i++) *arr_[i] = *rhs.arr_[i];
}

Vector& Vector::operator=(const Vector &rhs) {
    cap_ = rhs.capacity();
    size_ = rhs.size();
    arr_ = new value_type*[cap_];
    for (int i = 0; i < cap_; i++) arr_[i] = new value_type(0);
    for (int i = 0; i < size_; i++) *arr_[i] = *rhs.arr_[i];
    return *this;
}

reference Vector::front() {
    return *arr_[0];
}

reference Vector::back() {
    return *arr_[size_-1];
}

reference Vector::operator[](size_type pos) {
    return *arr_[pos];
}

const_reference Vector::operator[](size_type pos) const {
    return *arr_[pos];
}

size_type Vector::capacity() const {
    return cap_;
}

size_type Vector::size() const {
    return size_;
}

void Vector::clear() {
    size_ = 0;
}

bool Vector::empty() const {
    if (size_ == 0) return true;
    else return false;
}

void Vector::erase(size_type pos) {
    std::cout << "size = " << size_ << ", pos = " << pos << '\n';
    for (int i = pos; i < size_; i++) *arr_[i] = *arr_[i+1];
    size_--;
}

void Vector::insert(size_type pos, size_type cnt, const_reference val) {
    std::cout << "size = " << size_ << ", pos = " << pos << ", cnt = " << cnt << ", val = " << val << '\n';
    while (size_ + cnt > cap_) {
        cap_ += 10000;
        reserve(cap_);
    }
    for (int i = size_ + cnt - 1; i > pos; i--) {
        if (i - cnt < 0) break;
        *arr_[i] = *arr_[i-cnt];
        std::cout << i;
    }
    for (int i = 0; i < cnt; i++) *arr_[pos+i] = val;
    size_ += cnt;
}
void Vector::pop_back() {
    erase(size_ - 1);
}

void Vector::pop_front() {
    erase(0);
}

void Vector::push_back(const_reference val) {
    insert(size_, 1, val);
}

void Vector::push_front(const_reference val) {
    insert(0, 1, val);
}

void Vector::reserve(size_type new_capacity) {
    if (cap_ >= new_capacity) return;
    value_type *buf;
    buf = new value_type[new_capacity];
    for (int i = 0; i < size_; i++) buf[i] = *arr_[i];
    for (int i = 0; i < cap_; i++) delete arr_[i];
    delete[] arr_;
    arr_ = new value_type*[new_capacity];
    cap_ = new_capacity;
    for (int i = 0; i < cap_; i++) arr_[i] = new value_type(buf[i]);
    delete[] buf;
}

void Vector::shrink_to_fit() {
    value_type *buf;
    buf = new value_type[size_];
    for (int i = 0; i < size_; i++) buf[i] = *arr_[i];
    for (int i = 0; i < cap_; i++) delete arr_[i];
    delete[] arr_;
    arr_ = new value_type*[size_];
    cap_ = size_;
    for (int i = 0; i < cap_; i++) arr_[i] = new value_type(buf[i]);
    delete[] buf;
}