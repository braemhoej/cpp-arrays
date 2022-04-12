//
// Created by nicolaj on 4/10/22.
//

#ifndef ATB_ARRAY_H
#define ATB_ARRAY_H

#include <cstddef>

/**
 * Fixed capacity container for elements of type T. Stores elements dynamically.
 * @tparam T
 */
template <typename T>
class Array {
    typedef T* Pointer;
    typedef Pointer Iterator;
    typedef T& Reference;
    typedef std::size_t Size;
public:
    /**
     * Creates an empty array with zero capacity.
     */
    Array();
    /**
     * Creates new array with given capacity.
     * @param capacity
     */
    explicit Array(Size capacity);

    /**
     * Creates new array with given capacity, and fills it with copies of 't'.
     * @param capacity
     * @param t
     */
    Array(Size capacity, const T& fill);

    /**
     * Creates new array at begin. Doesn't deallocate data upon destruction.
     * @param begin T*
     * @param capacity unsigned long
     */
    Array(Pointer begin, unsigned long capacity);

    /**
     * Destructor. Deletes every element.
     */
    ~Array();

    /**
     * Unsafe container access.
     * @param index of element.
     * @return Reference.
     */
    Reference operator[](unsigned long index);
    /**
     * Returns a Pointer to the beginning of the array.
     * @return
     */
    Iterator begin();
    /**
     * Returns a Pointer to the end of the array, regardless of whether the space has been filled.
     * @return
     */
    Iterator end();

    /**
     * Fills the array with copies of the specified element.
     * @param t
     */
    void fill(const T& t);

    /**
     * Returns the Size (capacity) of the array.
     * @return size_t
     */
    Size size() const;

    /**
     * Returns a fresh copy of this array with a new address.
     * @return Array<T>
     */
    Array<T> copy();
private:
    Pointer container_;
    Size capacity_;
    bool auto_destruct;
};


#endif //ATB_ARRAY_H
