//
// Created by nicolaj on 4/10/22.
//

#include "../include/array.h"
#include <algorithm>

template <typename T>
Array<T>::Array() : container_(nullptr), capacity_(0), auto_destruct(false) { }

template <typename T>
Array<T>::Array(std::size_t capacity) : container_(new T[capacity]), capacity_(capacity), auto_destruct(true) { }

template <typename T>
Array<T>::Array(std::size_t capacity, const T& toFill) : container_(new T[capacity]), capacity_(capacity), auto_destruct(true) {
    fill(toFill);
}

template <typename T>
Array<T>::Array(Array<T>::Pointer begin, std::size_t capacity) : container_(begin), capacity_(capacity), auto_destruct(
        false) { }

template <typename T>
Array<T>::~Array() {
    if (auto_destruct)
        delete[] container_;
}

template <typename T>
typename Array<T>::Iterator Array<T>::begin() {
    return container_;
}

template <typename T>
typename Array<T>::Iterator Array<T>::end() {
    return container_ + capacity_;
}

template <typename T>
typename Array<T>::Reference Array<T>::operator[](unsigned long index) {
    return container_[index];
}

template <typename T>
void Array<T>::fill(const T& toFill) {
    std::fill_n(container_, capacity_, toFill);
}

template <typename T>
typename Array<T>::Size Array<T>::size() const {
    return capacity_;
}

template <typename T>
Array<T> Array<T>::copy() {
    Array<T> copy = Array<T>(capacity_);
    std::copy(begin(), end(), copy.begin());
    return copy;
}