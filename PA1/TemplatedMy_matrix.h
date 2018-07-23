
/* My_matrix.h
 
 Header file for the class My_matrix
 
 Write your name and UIN here
 
 */

#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>
using namespace std;
// Definitions of user defined type exceptions

struct invalid_input : public exception {
    virtual const char* what() const throw()
    { return "Invalid matrix input"; }
};

struct incompatible_matrices : public exception {
    virtual const char* what() const throw()
    { return "Incompatible matrices"; }
};

template<typename T>
class TemplatedMy_matrix {
    
    //member variables
    int m, n;
    T **ptr;
    void allocate_memory();  // optional
    
public:
    //member functions
    TemplatedMy_matrix();  // default constructor
    TemplatedMy_matrix(int m1, int n1); // parameter constructor
    ~TemplatedMy_matrix(); // destructor
    TemplatedMy_matrix(const TemplatedMy_matrix& mat); // copy constructor
    // My_matrix(My_matrix&& mat);  // move constructor (optional)
    
    TemplatedMy_matrix& operator=(const TemplatedMy_matrix& mat); //copy assignment operator
    // My_matrix& operator=(My_matrix&& mat); // move assignment operator (optional)
    
    int number_of_rows() const;
    int number_of_columns() const;
    
    T* operator()(int i) const; // overloaded to access to ith row
    T& operator()(int i, int j); // overloaded to access (i,j) element
    T& operator()(int i, int j) const; // overloaded to access (i,j) element
    
    T& elem(int i, int j) const; // overloaded to access (i,j) element
    T& elem(int i, int j); // overloaded to access (i,j) element
    
};

// see the handout for the description of these operators



template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix()
{
    ptr = nullptr;
    n = 0;
    m = 0;
}

template<typename T>
void TemplatedMy_matrix<T>::allocate_memory()
{
    // add your code here
    
}


template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(int m1, int n1)
{
    
    m = m1;
    n = n1;
    ptr = new T*[m1];
    
    for (int i = 0; i < m; ++i) {
        ptr[i] = new T [n1];
        if (typeid(T) == typeid(char)) {
            for (int j = 0; j < n; ++j) {
                ptr[i][j] = '0';
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                ptr[i][j] = {0};
            }
        }
        // DEBUG:
        /* cout << *ptr[i] << " ";
         for (int j = 0; j < n; ++j) {
         cout << (ptr[i][j]) << " ";
         }
         cout << endl;
         */
    }
}

template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(const TemplatedMy_matrix& mat)
{
    // add your code here
    m = mat.number_of_rows();
    n = mat.number_of_columns();
    
    ptr = new T*[m];
    
    for (int i = 0; i < m; ++i) {
        ptr[i] = new T [n];
        for (int j = 0; j < n; ++j) {
            elem(i,j) = mat.elem(i,j);
        }
    }
}

template <typename T>
TemplatedMy_matrix<T>::~TemplatedMy_matrix()
{
    // add your code here
    for (int i = 0; i < m; ++i) {
        delete [] ptr[i];
    }
    delete ptr;
    
    ptr = NULL;
}


// copy assignment operator
template <typename T>
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(const TemplatedMy_matrix& mat)
{
    // add your code here
    m = mat.number_of_rows();
    n = mat.number_of_columns();
    ptr = new T*[m];
    for (int i = 0; i < m; ++i) {
        ptr[i] = new T[n];
        for (int j = 0; j < n; ++j) {
            elem(i,j) = mat.elem(i,j);
        }
    }
    return *this;
}

template <typename T>
int TemplatedMy_matrix<T>::number_of_rows() const
{
    // add your code here
    return m;
}

template <typename T>
int TemplatedMy_matrix<T>::number_of_columns() const

{
    // add your code here
    return n;
}

template <typename T>
T* TemplatedMy_matrix<T>::operator()(int i) const
{
    return ptr[i];
}

template <typename T>
T& TemplatedMy_matrix<T>::operator()(int i, int j) const
{
    return ptr[i][j];
}

template <typename T>
T& TemplatedMy_matrix<T>::operator()(int i, int j)
{
    return ptr[i][j];
}

template <typename T>
T& TemplatedMy_matrix<T>::elem(int i, int j) const
{
    // add your code here
    // DEBUG:
    /*
     cout << "m = " << m << endl;
     cout << "i = " << i << endl;
     cout << "n = " << n << endl;
     cout << "j = " << j << endl;
     */
    if (i < 0 || i >= m) throw out_of_range("Out of range");
    if (j < 0 || j >= n) throw out_of_range("Out of range");
    
    return ptr[i][j];
    
}

template <typename T>
T& TemplatedMy_matrix<T>::elem(int i, int j)
{
    // add your code here
    // DEBUG:
    /*
     cout << "m = " << m << endl;
     cout << "i = " << i << endl;
     cout << "n = " << n << endl;
     cout << "j = " << j << endl;
     */
    if (i < 0 || i >= m) throw out_of_range("Out of range");
    if (j < 0 || j >= n) throw out_of_range("Out of range");
    
    return ptr[i][j];
}

template <typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat);

template <typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat);

template <typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);


template <typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);


template <typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat)
{
    
    for (int i = 0; i < mat.number_of_rows(); ++i) {
        for (int j = 0; j < mat.number_of_columns(); ++j) {
            out << mat.operator()(i,j) << " ";
        }
        out << endl;
    }
    
    return out;
}

template <typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat)
{
    int fileRow = 0;
    int fileCol = 0;
    for (int i = 0; i < 2; ++i) {
        if (i == 0) {
            in >> fileRow;
        }
        else if (i == 1) {
            in >> fileCol;
        }
    }
    
    if (fileRow == mat.number_of_rows() && fileCol == mat.number_of_columns()) {
        for (int i = 0; i < fileRow; ++i) {
            for (int j = 0; j < fileCol; ++j) {
                in >> mat.operator()(i,j);
            }
        }
    }
    
    return in;
}

template <typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
    if (mat1.number_of_columns() == mat2.number_of_columns() &&
        mat1.number_of_rows() == mat2.number_of_rows()) {
        // Temporary matrix
        TemplatedMy_matrix<T> tempMatrix(mat1.number_of_rows(), mat1.number_of_columns());
        
        for (int i = 0; i < mat1.number_of_rows(); ++i) {
            for (int j = 0; j < mat1.number_of_columns(); ++j) {
                tempMatrix.operator()(i,j) = mat1.operator()(i,j) + mat2.operator()(i,j);
            }
        }
        return tempMatrix;
    }
    
    else {
        throw incompatible_matrices();
    }
    
}

template <typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
    int temp = 0;
    if (mat1.number_of_columns() == mat2.number_of_rows()) {
        TemplatedMy_matrix<T> tempMatrix(mat1.number_of_rows(), mat2.number_of_columns());
        for (int i = 0; i < mat1.number_of_rows(); ++i) {
            for (int j = 0; j < mat2.number_of_columns(); ++j) {
                for (int k = 0; k < mat2.number_of_rows(); ++k) {
                    temp += mat1.operator()(i,k) * mat2.operator()(k,j);
                }
                tempMatrix.operator()(i,j) = temp;
                temp = 0;
            }
        }
        return tempMatrix;
    }
    else {
        throw incompatible_matrices();
    }
}




