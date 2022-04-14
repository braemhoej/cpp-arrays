//
// Created by nicolaj on 4/12/22.
//

#include <gtest/gtest.h>
#include "../src/array.hpp"

TEST(Initialization, ArraysCanBeInitializedWithValue) {
  Array<int> array = Array<int>(40, 42);
    for (int i = 0; i < array.size(); i++) {
        EXPECT_EQ(42, array[i]);
    }
}

TEST(Initialization, ArraysCanBeInitializedFromPointers) {
    int* pointer = new int[40];
    Array<int> array = Array<int>(pointer, 40);
    array.fill(42);
    for (int i = 0; i < array.size(); i++) {
        EXPECT_EQ(42, array[i]);
    }
}

TEST(Assignment, ArrayElementsCanBeReassigned) {
  Array<int> array = Array<int>(40, 42);
    array[10] = 10;
    for (int i = 0; i < array.size(); i++) {
        if (i != 10) {
            EXPECT_EQ(42, array[i]);
        } else {
            EXPECT_EQ(10, array[i]);
        }
    }
}

TEST(Size, ArraysSizeReturnsCapacity) {
  Array<int> array = Array<int>(40);
    EXPECT_EQ(40, array.size());
}