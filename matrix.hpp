#ifndef MATRIX_H_
#define MATRIX_H_
#include <vector>
#include <iostream>
template <typename T>
class Matrix
{
    private:

    size_t columns;
    size_t rows;
    std::vector<std::vector<T> > arr;

    public:
    Matrix(): columns(0), rows(0) {};
    Matrix(int columns, int rows);
    Matrix(std::vector<std::vector<T> > a);

    Matrix operator+(const Matrix & second) const;
    Matrix operator-(const Matrix & second) const;
    Matrix operator*(const Matrix & secons) const;
    bool operator==(Matrix & second);

    void upload();
    void push_back_row(std::vector<T> & vec);
    void push_back_column(std::vector<T> & vec);

    template<typename T>
    friend std::ostream & operator<<(std::ostream & os, const Matrix<T> & M);
};

template <typename T>
Matrix<T>::Matrix(int c, int r)
{
    columns = c;
    rows = r;
    arr.reserve(rows);
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T> > a)
{
    rows = a.size();
    if(rows > 0)
      columns = a[0].size();
    else 
        columns = 0;
    arr = a;
}

template <typename T>
void Matrix<T>::upload() 
{
    std::cout << "Wprowadź " << columns * rows <<   " wartosci: ";
    std::vector<T> temp_arr;
    temp_arr.reserve(columns);
    T temp;
    for(int i = 0; i < rows; ++i)
    {
        for(int i = 0; i < columns; ++i)
        {
            std::cin >> temp;
            temp_arr.push_back(temp);
        }
        arr.push_back(temp_arr);        
        temp_arr.clear();
    }
} 

template <typename T>
void Matrix<T>::push_back_row(std::vector<T> & vec)
{

    if(columns == 0 || vec.size() == columns)
    {
        arr.push_back(vec);
        columns = vec.size();
        rows++;
    }
}

template <typename T>
void Matrix<T>::push_back_column(std::vector<T> & vec)
{
    if(rows == 0 || vec.size() == rows)
    {
        for(int i = 0; i < rows; ++i)
        {
            arr[i].push_back(vec[i]);
            
        }
        rows = vec.size();
        columns++;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & s) const
{
    Matrix<T>output = *this;
    if(this->columns == s.columns && this->rows == s.rows)
    {
       for(int i = 0; i < this->arr.size(); ++i)
       {
           for( int j = 0; j < this->arr[i].size(); ++j)
           {
               output.arr[i][j] += s.arr[i][j];
           }
       } 
    }
    return output;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & s) const
{
    Matrix<T>output = *this;
    if(this->columns == s.columns && this->rows == s.rows)
    {
        for(int i = 0; i < this->arr.size(); ++i)
        {
            for( int j = 0; j < this->arr[i].size(); ++j)
            {
               output.arr[i][j] -= s.arr[i][j];
            }
        } 
    }
    return output;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & s) const
{
    Matrix<T> output;
    std::vector<T> temp;
    int support_value;
    if(this->columns == s.rows && this->rows == s.columns)
    {
        for(int x = 0; x < this->arr.size(); ++x)
        {
            for(int i = 0; i < s.columns; ++i)
            {
                support_value = 0;
                for(int j = 0; j < s.rows; ++j)
                {
                    support_value += arr[x][j] * s.arr[j][i];
                }
                temp.push_back(support_value);
            }
            output.push_back_row(temp);
            temp.clear();
        }
    }
    return output;
}

template<typename T>
bool Matrix<T>::operator==(Matrix<T> & second)
{
    if(this->columns == second.columns && this->rows == second.rows)
    {
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < columns; ++j)
            {
                if(this->arr[i][j] != second.arr[i][j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> & M)
 {
    for(int i = 0; i < M.arr.size(); ++i)
    {
        for(int j = 0; j < M.arr[i].size(); ++j)
        {
            os << M.arr[i][j];
            if(j + 1 < M.arr[i].size())
            {
                os << " ";
            }
            else
            {
              os << "\n";   
            }
            
        }
    }
    return os;
}
#endif
