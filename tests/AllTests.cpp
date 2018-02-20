#include <gtest/gtest.h>
#include "DAL.h"
#include "./SpecLoader.h"
#include "get_test.cpp"

int main(int argv, char** args){
    testing::InitGoogleTest(&argv, args);
    return RUN_ALL_TESTS();
}
