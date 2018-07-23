/*
 Implementation of the clas My_matrix
 */

#include "My_matrix.h"
#include <stdexcept>
#include <iostream>

My_matrix::My_matrix()
{
    ptr = NULL;
    n = 0;
    m = 0;
}

void My_matrix::allocate_memory()
{
    // add your code here
    
}

My_matrix::My_matrix(int m1, int n1)
{
    
    m = m1;
    n = n1;
    ptr = new int*[m1];
    
    for (int i = 0; i < m; ++i) {
        ptr[i] = new int [n1];
        for (int j = 0; j < n; ++j) {
            ptr[i][j] = 0;
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


My_matrix::My_matrix(const My_matrix& mat)
{
    // add your code here
    m = mat.number_of_rows();
    n = mat.number_of_columns();
    
    ptr = new int*[m];
    
    for (int i = 0; i < m; ++i) {
        ptr[i] = new int [n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            elem(i,j) = mat.elem(i,j);
        }
    }
}

// move constructor (optional)
/*
My_matrix::My_matrix(My_matrix&& mat)
{
    // add your code here
}
 */

My_matrix::~My_matrix()
{
    // add your code here
    for (int i = 0; i < m; ++i) {
        delete [] ptr[i];
    }
    delete ptr;
    
    ptr = NULL;
}

// copy assignment operator
My_matrix& My_matrix::operator=(const My_matrix& mat)
{
    // add your code here
    m = mat.number_of_rows();
    n = mat.number_of_columns();
    ptr = new int*[m];
    for (int i = 0; i < m; ++i) {
        ptr[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            elem(i,j) = mat.elem(i,j);
        }
    }
    return *this;
}


// move assignment operator (optional)
/*
My_matrix& My_matrix::operator=(My_matrix&& mat)
{
 
     delete ptr;
     m = mat.number_of_rows();
     n = mat.number_of_columns();
     ptr = new int* [m];
     for (int i = 0; i < m; ++i) {
     ptr[i] = new int [n];
     for (int j = 0; j < n; ++j) {
     elem(i,j) = mat.elem(i,j);
     }
     }
     
    return *this;
}
*/

int My_matrix::number_of_rows() const
{
    // add your code here
    return m;
}

int My_matrix::number_of_columns() const
{
    // add your code here
    return n;
}

int* My_matrix::operator()(int i) const
{
    return ptr[i];
}

int& My_matrix::operator()(int i, int j) const
{
    return ptr[i][j];
}

int& My_matrix::operator()(int i, int j)
{
    return ptr[i][j];
}

int& My_matrix::elem(int i, int j) const
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

int& My_matrix::elem(int i, int j)
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


ostream& operator<<(ostream& out, const My_matrix& mat)
{
    // add your code here
 
    for (int i = 0; i < mat.number_of_rows(); ++i) {
        for (int j = 0; j < mat.number_of_columns(); ++j) {
            out << mat.operator()(i,j) << " ";
        }
        out << endl;
    }
    
    return out;
}


istream& operator>>(istream& in, My_matrix& mat)
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


My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
    // add your code here
    
    // INCOMPLETE, NEED TO FIGURE OUT HOW TO PROPERLY ASSIGN THE RESULTANT
    // THROUGH USING THE MOVE ASSIGNMENT OPERATOR
    
    if (mat1.number_of_columns() == mat2.number_of_columns() &&
        mat1.number_of_rows() == mat2.number_of_rows()) {
        // temporary matrix
        My_matrix tempMatrix(mat1.number_of_rows(), mat1.number_of_columns());
        // DEBUG:
        /*
         cout << "tempMatrix rows: " << tempMatrix.number_of_rows() << endl;
         cout << "tempMatrix columns: " << tempMatrix.number_of_columns() << endl;
         */
        
        for (int i = 0; i < mat1.number_of_rows(); ++i) {
            for (int j = 0; j < mat1.number_of_columns(); ++j) {
                tempMatrix.operator()(i,j) = mat1.operator()(i,j) + mat2.operator()(i,j);
                // DEBUG:
                /*
                cout << "elem at" << i << "," << j << " is:"
                << tempMatrix.elem(i,j) << endl;
                 */
            }
        }
        return tempMatrix;
    }
    
    else {
        throw incompatible_matrices();
    }
    
}


My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
{
    // add your code here
    int temp = 0;
    if (mat1.number_of_columns() == mat2.number_of_rows()) {
        My_matrix tempMatrix(mat1.number_of_rows(), mat2.number_of_columns());
        for (int i = 0; i < mat1.number_of_rows(); ++i) {
            for (int j = 0; j < mat2.number_of_columns(); ++j) {
                for (int k = 0; k < mat2.number_of_rows(); ++k) {
                    temp += mat1.operator()(i,k) * mat2.operator()(k,j);
                }
                tempMatrix.operator()(i,j) = temp;
                temp = 0;
            }
            cout << endl;
            
        }
        
        return tempMatrix;
    }
    else {
        throw incompatible_matrices();
    }
}

