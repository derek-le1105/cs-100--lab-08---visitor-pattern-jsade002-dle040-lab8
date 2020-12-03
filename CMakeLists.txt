CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test  
    containers/list_container.cpp
    unit_test.cpp
    containers/VectorContainer.cpp
    sorts/SelectionSort.cpp
    sorts/bubble_sort.cpp
    binary_iterator.cpp
)

ADD_EXECUTABLE(calculator
    main.cpp
    binary_iterator.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

