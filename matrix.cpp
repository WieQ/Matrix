#include <iostream>
#include "matrix.hpp"

int main()
{
// Matrix<int> m (3,3);
 //m.upload();
 //std::cout << m << std::endl;
 //Matrix<int> l(m);
 //std::cout << l << std::endl;

 Matrix<int> g (std::vector<std::vector<int> >{{1,2,3},{4,5,6}});
 Matrix<int> g2 (std::vector<std::vector<int> >{{7,8},{9,10},{11,12}});
 
 std::cout << g * g2;
}