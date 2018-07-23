// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
// #include "My_matrix.h"
#include "TemplatedMy_matrix.h"
#include <iomanip>

int main(){
    
    // Some test cases are expected to throw an exception.
    // Add more try and catch blocks as necessary for your code
    // to finish execution.
    
    try{
        // Test 1
        // * Create an object of type My_matrix, called m1, using constructor
        // * Initialize m1 in main (by assigning numbers to matrix elements)
        // * Display m1 on the screen using the operator <<
        
        // int case
        cout << "\nTEST 1: " << endl << endl;
        TemplatedMy_matrix<int> m1_int(3,3);
        m1_int.elem(0 , 0) = 3;
        m1_int.elem(1 , 1) = 6;
        m1_int.elem(2 , 2) = 9;
        cout << "m1_int:\n" << m1_int;
        
        // double case
        TemplatedMy_matrix<double> m1_double(3,3);
        m1_double(0, 0) = 3.5;
        m1_double(1, 1) = 6.5;
        m1_double(2, 2) = 9.5;
        cout << "m1_double: \n" << m1_double;
        
        // char case
        TemplatedMy_matrix<char> m1_char(3,3);
        m1_char(0, 0) = 'a';
        m1_char(1, 1) = 'b';
        m1_char(2, 2) = 'c';
        cout << "m1_char: \n" << m1_char;
        
        // Test 2
        // * Create an object of type My_matrix, called m2, using (default)
        //   constructor
        // * Open an input file containing a matrix (row by row)
        // * Initialize m2 by reading from the input file using
        //   the operator >>
        // * Open an output file (can be empty)
        // * Write m2 to the output file using the operator <<
        
        cout << "\nTEST 2: " << endl << endl;
        
        // int case
        TemplatedMy_matrix<int> m2;
        // My >> operator checks for incorrect size so I cannot use it with the default constructor who has size 0x0
        TemplatedMy_matrix<int> m2_int(6,3);
        ifstream ist;
        string file2Int = "matrix2_int.txt";
        ist.open(file2Int);
        if (!ist) {
            cout << "no file located" << endl;
        }
        else {
            cout << "reading file: " << file2Int << "...\n";
        }
        ist >> m2_int;
        ist.close();
        
        cout << "m2_int: \n" << m2_int;
        ofstream ost;
        string outputFileInt = "output_int.txt";
        ost.open(outputFileInt);
        ost << m2_int;
        ost.close();
        cout << "\nfile named " << outputFileInt << " written...\n\n";
        
        // double case
        TemplatedMy_matrix<double> m2_double(6,3);
        ifstream istd;
        string file2Double = "matrix2_double.txt";
        istd.open(file2Double);
        if (!istd) {
            cout << "no file located" << endl;
        }
        else {
            cout << "reading file: " << file2Double << "...\n";
        }
        istd >> m2_double;
        istd.close();
        
        cout << "m2_double: \n" << m2_double;
        ofstream ostd;
        string outputFileDouble = "output_double.txt";
        ostd.open(outputFileDouble);
        ostd << m2_double;
        ostd.close();
        cout << "\nfile named " << outputFileDouble << " written...\n\n";
        
        // char case
        TemplatedMy_matrix<char> m2_char(6,3);
        ifstream istc;
        string file2Char = "matrix2_char.txt";
        istc.open(file2Char);
        if (!istc) {
            cout << "no file located" << endl;
        }
        else {
            cout << "reading file: " << file2Char << "...\n";
        }
        istc >> m2_char;
        istc.close();
        
        cout << "m2_char: \n" << m2_char;
        ofstream ostc;
        string outputFileChar = "output_char.txt";
        ostc.open(outputFileChar);
        ostc << m2_char;
        ostc.close();
        cout << "\nfile named " << outputFileChar << " written...\n\n";
        
        // Test 3
        // * Use the copy constructor to make a copy of m1 called m3
        // * Apply the copy assignment to m1 called m4
        // * Display m3 and m4 on the screen using the operator <<
        
        cout << "\nTEST 3:\n\n";
        
        
        // int case
        TemplatedMy_matrix<int> m3_int(m1_int);
        cout << "constructing m3_int from m1_int...\nm3_int: \n" << m3_int;

        TemplatedMy_matrix<int> m4_int;
        m4_int = m1_int;
        cout << "copying m1_int into m4_int..." << endl << "m4_int: " <<
        endl << m4_int << endl;

        
        // double case
        TemplatedMy_matrix<double> m3_double(m1_double);
        cout << "constructing m3_double from m1_double...\nm3double: \n" <<
        m3_double;
        
        TemplatedMy_matrix<double> m4_double;
        m4_double = m1_double;
        cout << "copying m1_double into m4_double...\nm4_double: " <<
        endl << m4_double << endl;
        
        
        // char case
        TemplatedMy_matrix<char> m3_char(m1_char);
        cout << "constructing m3_char from m1_char...\nm3char: \n" << m3_char
        << endl;
        
        TemplatedMy_matrix<char> m4_char;
        m4_char = m1_char;
        cout << "copying m1_char into m4_char...\nm4_char: " <<
        endl << m4_char;
        
        // Test 4
        // * Test the matrix multiplication operator (operator*)
        // * Apply the multiplication operator to valid and invalid cases
        // * Display the resulting matrix and its number of rows and columns
        

        cout << "\nTEST 4: " << endl << endl;
        // int case
        TemplatedMy_matrix<int> matrix26_int(2,6);
        ifstream isi4;
        isi4.open("matrix1_int.txt");
        if (!isi4) {
            cout << "no file inputted" << endl;
        }
        isi4 >> matrix26_int;
        cout << "matrix 2x6 (int): " << endl << matrix26_int << "\n";
        isi4.close();
        
        ifstream isi4_2;
        TemplatedMy_matrix<int> matrix63_int(6, 3);
        isi4_2.open("matrix2_int.txt");
        if (!isi4_2) {
            cout << "no file inputted" << endl;
        }
        isi4_2 >> matrix63_int;
        cout << "matrix 6x3" << endl << matrix63_int << "\n";
        
        cout << "multiplication gives...\n" << matrix26_int * matrix63_int << "\n";
        isi4_2.close();
        
        // double case
        TemplatedMy_matrix<double> matrix26_double(2,6);
        ifstream isd4;
        isd4.open("matrix1_double.txt");
        if (!isd4) {
            cout << "no file inputted" << endl;
        }
        
        isd4 >> matrix26_double;
        cout << "matrix 2x6_double: " << endl << matrix26_double << "\n";
        isd4.close();
        
        ifstream isd4_2;
        TemplatedMy_matrix<double> matrix63_double(6, 3);
        isd4_2.open("matrix2_double.txt");
        if (!isd4_2) {
            cout << "no file inputted" << endl;
        }
        isd4_2 >> matrix63_double;
        cout << "matrix 6x3_double" << endl << matrix63_double << "\n";
        
        TemplatedMy_matrix<double> result = matrix26_double * matrix63_double;
        cout.precision(1);
        cout << fixed << "multiplication gives...\n" << result
         << "\n";
        isd4_2.close();
        
        // char case
        TemplatedMy_matrix<char> matrix26_char(2,6);
        ifstream isc4;
        isc4.open("matrix1_char.txt");
        if (!isc4) {
            cout << "no file inputted" << endl;
        }
        
        isc4 >> matrix26_char;
        cout << "matrix 2x6_char: " << endl << matrix26_char << "\n";
        isc4.close();
        
        ifstream isc4_2;
        TemplatedMy_matrix<char> matrix63_char(6, 3);
        isc4_2.open("matrix2_char.txt");
        if (!isc4_2) {
            cout << "no file inputted" << endl;
        }
        isc4_2 >> matrix63_char;
        cout << "matrix 6x3_char" << endl << matrix63_char << "\n";
        
        TemplatedMy_matrix<char> result2 = matrix26_char * matrix63_char;
        cout.precision(1);
        cout << fixed << "multiplication gives...\n" << result2
        << "\n";
        isc4_2.close();
        
        // INVALID CASE
        // cout << "\ninvalid case for test 4..." << endl;
        // cout << matrix63 * matrix26;
        
        // Test 5
        // * Test the matrix addition operator (operator+)
        // * Apply the multiplication operator to valid and invalid cases
        // * Display the resulting matrix and its number of rows and columns
        
//        cout << "\nTEST 5\n\n";
//        cout << "m1 + m3 yields..." << endl;
//        cout << m1 + m3;
        
        // INVALID CASE
        // cout << "\ninvalid case for test 5..." << endl;
        // cout << m1 + m2;
        
    } catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
