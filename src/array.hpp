//
// Created by nicolaj on 4/10/22.
//

#ifndef ATB_ARRAY_H
#define ATB_ARRAY_H

#include <algorithm>
#include <cstddef>

namespace arrays {

/**
 * Fixed capacity container for elements of type T. Stores elements dynamically.
 * @tparam T
 */
template <class T> class array {
public:
  typedef T *pointer;
  typedef T *iterator;
  typedef T &reference;
  typedef T &const_reference;
  typedef std::size_t size_type;
  /**
   * Creates an empty array with zero capacity.
   */
  array() : head_(nullptr), length_(0) {}

  /**
   * Creates new array with given capacity.
   * @param capacity
   */
  explicit array(size_type capacity)
      : head_(new T[capacity]), length_(capacity){};

  /**
   * Creates new array with given capacity, and fills it with copies of 't'.
   * @param capacity
   * @param t
   */
  array(size_type capacity, const T &t)
      : head_(new T[capacity]), length_(capacity) {
    fill(t);
  }

  /**
   * Creates new array at begin. Doesn't deallocate data upon destruction.
   * @param begin T*
   * @param capacity unsigned long
   */
  array(pointer begin, unsigned long capacity)
      : head_(begin), length_(capacity), auto_destruct(false) {}

  /**
   * Creates new array as 'fresh' copy of 'initializer'.
   * The newly-created %array contains the copies of the contents of the copied
   * instance.
   * @param instance
   */
  array(const array &instance)
      : head_(new T[instance.size()]), length_(instance.size()), auto_destruct(instance.auto_destruct) {
    std::copy(instance.head_, instance.head_ + instance.length_, begin());
  }

  /**
   * @brief Move assignment operator.
   * @param instance
   * @return
   */
  array &operator=(array &&instance) noexcept {
    array<T> temporary;
    swap(instance);
    instance.swap(temporary);
    return *this;
  }

  array &operator=(const array &instance) = default;
      /**
   * Destructor. Deletes every element.
   */
  ~array() {
    if (auto_destruct)
      delete[] head_;
  }

  /**
   * Unsafe container access.
   * @param index of element.
   * @return reference.
   */
  reference operator[](unsigned long index) { return head_[index]; }

  /**
   * Unsage container access.
   * @param index of element.
   * @return const reference.
   */
  const_reference operator[](unsigned long index) const { return head_[index]; }

  /**
   * Returns a pointer to the beginning of the array.
   * @return
   */
  iterator begin() { return head_; }
  /**
   * Returns a pointer to the end of the array, regardless of whether the space
   * has been filled.
   * @return
   */
  iterator end() { return head_ + length_; }

  /**
   * Fills the array with copies of the specified element.
   * @param t
   */
  void fill(const T &t) { std::fill_n(head_, length_, t); }

  /**
   * Returns the size_type (capacity) of the array.
   * @return size_t
   */
  [[nodiscard]] size_type size() const { return length_; }

  /**
   * Returns a fresh copy of this array with a new address.
   * @return array<T>
   */
  array<T> copy() {
    array<T> copy = array<T>(length_);
    std::copy(begin(), end(), copy.begin());
    return copy;
  }

  /**
   * Set internal container and capacity.
   * @param container T*
   * @param capacity size_type
   */
  void set(T *container, size_type capacity) {
    head_ = container;
    length_ = capacity;
  }

private:
  // Pointer to the head of the dynamically allocated memory.
  pointer head_;
  // Length (# of T) of allocated memory.
  size_type length_;
  // Boolean specifying whether the head_ should be destroyed when object is
  // destroyed.
  bool auto_destruct = true;

  void copy(array<T> &instance) {
    head_ = instance.head_;
    length_ = instance.length_;
    auto_destruct = instance.auto_destruct;
  }
  void swap(array<T> &instance) {
    array<T> temporary;
    temporary.copy(*this);
    copy(instance);
    instance.copy(temporary);
  }
};

} // namespace array

#endif // ATB_ARRAY_H
