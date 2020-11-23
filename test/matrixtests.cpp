#include <gtest/gtest.h>
#include "../matrix.hpp"

TEST(addition_test, adition)
{
    Matrix<int> test(std::vector<std::vector<int> > {{2,4,6},{8,10,12},{14,16,18}}); 
    Matrix<int> test2(std::vector<std::vector<int> > {{1,2,3},{4,5,6},{7,8,9}}); 
    EXPECT_EQ(true, test == (test2+test2));
    
}

TEST(substraction_test, substract)
{
    Matrix<int> test(std::vector<std::vector<int> > {{2,4,6},{8,10,12},{14,16,18}}); 
    Matrix<int> test2(std::vector<std::vector<int> > {{1,2,3},{4,5,6},{7,8,9}}); 
    EXPECT_EQ(true, test2 == (test - test2));
}


TEST(multiplying_test, multyply)
{
    Matrix<int> x(std::vector<std::vector<int> > {{1,2,3},{4,5,6}});
    Matrix<int> y(std::vector<std::vector<int> >{{7,8},{9,10},{11,12}});
    Matrix<int> output (std::vector<std::vector<int> > {{58,64},{139,154}});
    EXPECT_EQ(true, output == (x * y)) << "Expected:\n" << output << "\nGot:\n" << x*y; 
}