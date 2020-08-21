#include <iostream>
#include "mymatrix.h"
using namespace std;

void testParameterizedConstructor(mymatrix<int> M1)
{
    cout << "** Testing Parmeterized Constructor **" << endl;
    M1._output();
    cout << endl;
}

void testCopyConstructor(mymatrix<int> M1, mymatrix<int> M2)
{
    cout << "** Testing Copy Constructor **" << endl; 
    
    M2 = M1;
    
    M1._output();
    cout << endl;
    M2._output();
    cout << endl;
}

void testNumRows(mymatrix<int> M1)
{
    cout << "** Testing Number of Rows **" << endl;
    cout << M1.numrows() << endl;
}

void testNumCols(mymatrix<int> M1)
{
    cout << "** Testing Number of Columns **" << endl;
    cout << M1.numcols(0) << endl;
}

void testGrowCols(mymatrix<int> M1)
{
    cout << "** Testing Grow Columns **" << endl;
    M1.growcols(0,6);
    M1._output();
    cout << endl;
}

void testGrow(mymatrix<int> M1)
{
    cout << "** Testing Grow **" << endl;
    
    M1._output(); // Print 4 x 4
    cout << endl;
    M1.grow(6,6);
    M1._output(); // Print 6 x 6
    cout << endl;
}

void testSize(mymatrix<int> M1)
{
    cout << "** Testing Size **" << endl;
    cout << M1.size() << endl;
}

void testScalarMult(mymatrix<int> &M1, mymatrix<int> &M2)
{
    cout << "** Testing Scalar Multiplication **" << endl;
    
    M1(0,0) = 5;
    M1(1,1) = 5;
    M1(2,2) = 5;
    M1(3,3) = 5;
    
    M1._output();
    cout << endl;
    M2 = M1 * 2;
    M2._output();
    cout << endl;
}

void testMatrixMult(mymatrix<int> &M1, mymatrix<int> &M2, mymatrix<int> &M3)
{
    cout << "** Testing Matrix Multiplication **" << endl;
    
    M1(0,0) = 5;
    M1(1,0) = 5;
    M1(2,0) = 5;
    M1(3,0) = 5;
    
    M2(0,0) = 10;
    M2(0,1) = 10;
    M2(0,2) = 10;
    M2(0,3) = 10;
    
    M1._output();
    cout << endl;
    M2._output();
    cout << endl;
    M3 = M1 * M2;
    M3._output();
    cout << endl;
}

void displayMenu()
{
    cout << "Choose a test case for mymatrix"      << endl; 
    cout << "-------------------------------"      << endl;
    cout << "1. Test Parmeterized Constructor"     << endl;
    cout << "2. Test Copy Constructor"             << endl;
    cout << "3. Test Number of Rows"               << endl;
    cout << "4. Test Number of Columns"            << endl;
    cout << "5. Test Grow Columns Function"        << endl;
    cout << "6. Test the Grow Function"            << endl;
    cout << "7. Test the Size of the Matrix"       << endl;
    cout << "8. Test Scalar Multiplication"        << endl;
    cout << "9. Test Matrix Multiplication"        << endl;
    cout << "10. Exit the Program"         << endl << endl;
}
    
int main()
{
    mymatrix<int> M1;
    mymatrix<int> M2;
    mymatrix<int> M3;
    int userInput; 
    
    do 
    {
        M1(0, 0) = 123;
        M1(1, 1) = 456;
        M1(2, 2) = 789;
        M1(3, 3) = -99;
        
        displayMenu();
        cin >> userInput;
        
        switch(userInput)
        {
            case 1: testParameterizedConstructor(M1);
                    break;
            case 2: testCopyConstructor(M1,M2);
                    break;
            case 3: testNumRows(M1);
                    break;
            case 4: testNumCols(M1);
                    break;
            case 5: testGrowCols(M1);
                    break;
            case 6: testGrow(M1);
                    break;
            case 7: testSize(M1);
                    break;
            case 8: testScalarMult(M1,M2);
                    break;
            case 9: testMatrixMult(M1,M2,M3);
                    break;
            case 10: exit(0);
                    break;
            default: cout << "Error not a valid choice" << endl;
                    break;
        }
    } while(true);

    return 0;
}