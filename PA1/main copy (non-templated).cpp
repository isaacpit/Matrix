// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
// #include "My_matrix.h"
#include "TemplatedMy_matrix.h"

int main(){
    
    // Some test cases are expected to throw an exception.
    // Add more try and catch blocks as necessary for your code
    // to finish execution.
    
    try{
        // DEBUG:
        /*
        My_matrix matrix(4, 4);
        cout << "matrix:" << endl;
        cout << matrix;
        My_matrix matrix1(4, 4);
        cout << "matrix1:" << endl;
        cout << matrix1;
        
        
        // DEBUG:
        // cout << "element at 1,1 is : " << matrix.elem(1,1) << endl;
        matrix.elem(1,1) = 1;
        cout << "matrix with 1 added to 1,1: " << endl;
        cout << matrix;
        
        
        My_matrix matrix2(matrix);
        cout << "matrix2 using copy constructor: " << endl;
        cout << matrix2;
        
        
        matrix1.elem(3,3) = 5;
        cout << "matrix1 with 5 at 3,3:" << endl;
        cout << matrix1;
        
        
        matrix2 = matrix1;
        cout << "matrix1 copied to matrix2, should be same: " << endl;
        cout << matrix2;
         
        
        // MATRIX ADDITION DEBUG CODE
        
        // My_matrix sumMatrix(4 , 4);
        My_matrix sumMatrix = matrix + matrix1;
        cout << "sumMatrix addition: " << endl;
        cout << sumMatrix;
        
        // DEBUG:
        
        cout << "testing matrix" << endl;
        cout << matrix;
        
         
         sumMatrix.elem(1,1) = 5;
         cout << "sumMatrix with 5 added:" << endl;
         sumMatrix.print_matrix();
         
        
        
         cout << matrix[0,0];
         for (int i = 0; i < matrix.number_of_rows(); ++i) {
         for (int j = 0; j < matrix.number_of_columns(); ++j) {
         cout << matrix.operator()(i, j) << " ";
         }
         }
         cout << endl;
         */
        
        // Test 1
        // * Create an object of type My_matrix, called m1, using constructor
        // * Initialize m1 in main (by assigning numbers to matrix elements)
        // * Display m1 on the screen using the operator <<
        
        cout << "\nTEST 1: " << endl << endl;
        TemplatedMy_matrix<int> m1(3,3);
        m1.elem(0 , 0) = 3;
        m1.elem(1 , 1) = 6;
        m1.elem(2 , 2) = 9;
        cout << "m1:\n" << m1;
        
        // Test 2
        // * Create an object of type My_matrix, called m2, using (default)
        //   constructor
        // * Open an input file containing a matrix (row by row)
        // * Initialize m2 by reading from the input file using
        //   the operator >>
        // * Open an output file (can be empty)
        // * Write m2 to the output file using the operator <<
        
        cout << "\nTEST 2: " << endl << endl;
        TemplatedMy_matrix<int> m2;
        // My >> operator checks for incorrect size so I cannot use it with the default constructor who has size 0x0
        TemplatedMy_matrix m2_2(6,3);
        ifstream ist;
        ist.open("matrix2.txt");
        if (!ist) {
            cout << "no file located" << endl;
        }
        ist >> m2_2;
        ist.close();
        
        cout << "m2: \n" << m2_2;
        ofstream ost;
        ost.open("test3.txt");
        ost << m2_2;
        ost.close();
        cout << "\nfile written..." << endl;
        
        // Test 3
        // * Use the copy constructor to make a copy of m1 called m3
        // * Apply the copy assignment to m1 called m4
        // * Display m3 and m4 on the screen using the operator <<
        
        cout << "\nTEST 3:" << endl << endl;
                My_matrix m3(m1);
        cout << "constructing m3 from m1..." << endl << "m3: " << endl << m3;

        My_matrix m4;
        m4 = m1;
        cout << "copying m1 into m4..." << endl << "m4: " << endl << m4;

        
        // Test 4
        // * Test the matrix multiplication operator (operator*)
        // * Apply the multiplication operator to valid and invalid cases
        // * Display the resulting matrix and its number of rows and columns
        
        cout << "\nTEST 4: " << endl << endl;
        My_matrix matrix26(2,6);
        ifstream is;
        is.open("matrix1.txt");
        if (!is) {
            cout << "no file inputted" << endl;
        }
        is >> matrix26;
        cout << "matrix 2x6: " << endl << matrix26 << "\n";
        is.close();
        
        ifstream is2;
        My_matrix matrix63(6, 3);
        is2.open("matrix2.txt");
        if (!is2) {
            cout << "no file inputted" << endl;
        }
        is2 >> matrix63;
        cout << "matrix 6x3" << endl << matrix63 << "\n";
        
        cout << "multiplication gives...\n" << matrix26 * matrix63 << "\n";
        

        
        // INVALID CASE
        // cout << "\ninvalid case for test 4..." << endl;
        // cout << matrix63 * matrix26;
        
        
        // Test 5
        // * Test the matrix addition operator (operator+)
        // * Apply the multiplication operator to valid and invalid cases
        // * Display the resulting matrix and its number of rows and columns
        
        cout << "\nTEST 5\n\n";
        cout << "m1 + m3 yields..." << endl;
        cout << m1 + m3;
        
        // INVALID CASE
        // cout << "\ninvalid case for test 5..." << endl;
        // cout << m1 + m2;
        
    } catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
