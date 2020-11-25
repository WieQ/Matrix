#include <iostream>
#include "matrix.hpp"
#include <memory>
#include <cctype>

void Matrix_Menu();
std::shared_ptr<Matrix<int>> Create_Matrix();

int main()
{
    Matrix_Menu();
    return 0;
}

void Matrix_Menu()
{
    std::vector<std::shared_ptr<Matrix<int>>> Matrix_arr;
    char chose;
    do
    {
        std::cout << "There is: " << Matrix_arr.size();
        if(Matrix_arr.size() == 1)
        {
            std::cout << " Matrix!";
        }
        else
        {
            std::cout << " Matrices!";
        }
        std::cout << std::endl;

        std::cout << "You can:\n1.Create new Matrix(MAX 10 Matricex at once)\t";
        if( Matrix_arr.size() > 0)
        {
            std::cout << "2.Delete Existing one\n3.Multyply by value\t";
            if(Matrix_arr.size() > 1)
            {
                std::cout << "4.Matrix addition\n5.Matrix Substraction\t";
                std::cout << "6.Matrix Multiplication\n";
            }
        }
        std::cout << "q.Quit" <<std::endl;
        std::cin.get(chose);
        switch (chose)
        {
        case '1':
            if(Matrix_arr.size() < 11)
            {
                Matrix_arr.push_back(Create_Matrix());
            }
            else
            {
                std::cout << "Reached Limit of Matrices! " << Matrix_arr.size();
            }
            
            break;
        case '2':
        {
            unsigned int which;
            std::cout << "Chose Which Matrix you want to delete\n";
            for(auto i = 0; i < Matrix_arr.size(); ++i)
            {
                std::cout  << i + 1 << ": " << *(Matrix_arr[i]) << std::endl;
            }
            std::cin >> which;
            if( which != 0 && (which - 1) < Matrix_arr.size()) 
            {
                Matrix_arr.erase(Matrix_arr.begin() + (which - 1));
            }
            std::cout << "Deleted " << which << "Matrix!" << std::endl;
        }   
            break;
        case '3':
        {
            int value;
            unsigned int which;
            std::cout << "Chose Which Matrix you want o Myltiply by Value\n";
            for(auto i = 0; i < Matrix_arr.size(); ++i)
            {
                std::cout << i + 1 << ": " << *(Matrix_arr[i]) << std::endl;
            }
            std::cin >> which;
            which--;
            if( which >= 0 && which < Matrix_arr.size()) 
            {
                std::cout << "Insert Value: ";
                if(std::cin >> value )
                {  
                    std::cout << *(Matrix_arr[which]) << std::endl;
                    std::cout << "*\n";
                    std::cout << value << std::endl;
                    *(Matrix_arr[which]) = *(Matrix_arr[which]) * value;
                    std::cout << "||" << std::endl;
                    std::cout << *(Matrix_arr[which]) << std::endl;
                }          
            }
            else
            {
                std::cout << "Your choice was out of arrays Bounds! " << which << " > " << Matrix_arr.size() << std::endl;
            }
        }   
            break;
        case '5':
        {
            unsigned int First_term;
            unsigned int Second_term;
            std::cout << "Chose First term\n";
            for(auto i = 0; i < Matrix_arr.size(); ++i)
            {
                std::cout  << i + 1 << ": "  << *(Matrix_arr[i]) << std::endl;
            }
            std::cin >> First_term;
            std::cout << "Chose Second term: ";
            std::cin >> Second_term;
            First_term--;
            Second_term--;
            if(First_term >= 0 && Second_term >= 0 && First_term < Matrix_arr.size() && Second_term < Matrix_arr.size())
            {
                std::cout << *(Matrix_arr[First_term]) << std::endl;
                std::cout << "+\n";
                std::cout << *(Matrix_arr[Second_term]) << std::endl;
                *(Matrix_arr[First_term]) = *(Matrix_arr[First_term]) + *(Matrix_arr[Second_term]);
                std::cout << "||" << std::endl;
                std::cout << *(Matrix_arr[First_term]) << std::endl;
            }
            else
            {
                std::cout << "One of Your choice was out of arrays Bounds! " <<  std::endl;
            }
            break;
        }
        case '4':
        {
            unsigned int First_term;
            unsigned int Second_term;
            std::cout << "Chose First term\n";
            for(auto i = 0; i < Matrix_arr.size(); ++i)
            {
                std::cout  << i + 1 << ": "  << *(Matrix_arr[i]) << std::endl;
            }
            std::cin >> First_term;
            std::cout << "Chose Second term: ";
            std::cin >> Second_term;
            First_term--;
            Second_term--;
            if(First_term >= 0 && Second_term >= 0 && First_term < Matrix_arr.size() && Second_term < Matrix_arr.size())
            {
                std::cout << *(Matrix_arr[First_term]) << std::endl;
                std::cout << "-\n";
                std::cout << *(Matrix_arr[Second_term]) << std::endl;
                *(Matrix_arr[First_term]) = *(Matrix_arr[First_term]) - *(Matrix_arr[Second_term]);
                std::cout << "||" << std::endl;
                std::cout << *(Matrix_arr[First_term]) << std::endl;
            }
            else
            {
                std::cout << "One of Your choice was out of arrays Bounds! " <<  std::endl;
            }
            break;
        }
        case '6':
        {
            unsigned int First_factor;
            unsigned int Second_factor;
            std::cout << "Chose First factor\n";
            for(auto i = 0; i < Matrix_arr.size(); ++i)
            {
                std::cout  << i + 1 << ": "  << *(Matrix_arr[i]) << std::endl;
            }
            std::cin >> First_factor;
            std::cout << "Chose Second factor: ";
            std::cin >> Second_factor;
            First_factor--;
            Second_factor--;
            if(First_factor >= 0 && Second_factor >= 0 && First_factor < Matrix_arr.size() && Second_factor < Matrix_arr.size())
            {
                std::cout << *(Matrix_arr[First_factor]) << std::endl;
                std::cout << "*\n";
                std::cout << *(Matrix_arr[Second_factor]) << std::endl;
                *(Matrix_arr[First_factor]) = *(Matrix_arr[First_factor]) * *(Matrix_arr[Second_factor]);
                std::cout << "||" << std::endl;
                std::cout << *(Matrix_arr[First_factor]) << std::endl;
            }
            else
            {
                std::cout << "One of Your choice was out of arrays Bounds! " <<  std::endl;
            }
        }
        }
        while(std::cin.get() != '\n')
                continue;
            std::cin.clear();
            std::cin.sync();
    }while(tolower(chose) != 'q');
}

std::shared_ptr<Matrix<int>> Create_Matrix()
{
        unsigned int size_c;
        unsigned int size_r;
        std::cout << "Insert size of columns: ";
        while(!(std::cin >> size_c))
        {
            std::cout << "Error, wrong value! " ;
            std::cout << "Insert size of columns: " << std::endl;
            std::cin.clear();
            std::cin.sync();
            while(std::cin.get() != '\n')
              continue;
        }
        std::cout << "Insert size of rows: ";
        while(!(std::cin >> size_r))
        {
            std::cout << "Error, wrong value! " ;   
            std::cout << "Insert size of rows: " << std::endl;
            std::cin.clear();
            while(std::cin.get() != '\n')
                continue;
        }
        std::shared_ptr<Matrix<int>> temp_Matrix(new Matrix<int>(size_c,size_r));
        temp_Matrix->upload();
        std::cout << "Creating Matrix Completed!\n" << *temp_Matrix << std::endl;
        return temp_Matrix;
}