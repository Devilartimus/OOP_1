#include <iostream>
#include "classCode.cpp"

using namespace std;
using namespace Vec;


int main()
{
    vectora A(1,2,3);

    //тест сеттера
    cout << "Testing functions for accessing class members \n"
       <<"---> Coordinate Setters (Data entry)\n";
    A.setX(4);
    A.setY(5);
    A.setZ(5);
    cin>>A;

    //тест геттера
    cout << "---> Coordinate geters (Reading data)\n"
        << "x = " << A.getX() << "; y = " << A.getY() << "; z = " << A.getZ() << endl
        << "Calculating the modulus (length) of a vector: " <<A.module() << endl << endl;

    //тест копирования
    vectora B;
    cout << "\n Copying a vector "<< A << " to vector " << B << endl;
    cout << "Result: " << B.copyVector(A) << endl << endl;

    //тест умножения на скаляр
    cout << "\n\n Multiplication of a vector by a scalar.\n Enter a scalar value: ";
    double scal;
    cin >> scal;
    cout << B << " * " << scal << " = " << B * scal << endl;

    //тест нормирования вектора
    cout << "\n Vector normalization---> Result: " << B.normVec() << endl;
    cout << "Length: " << B.module() << endl;

    //тест операций над векторами
    cout << "\n double operations on vectors A and B to obtain a new vector C \n" << endl
         << "Addition: " << A << " + " << B << " = " << A + B << endl <<endl
         << " Difference: " << A << " - " << B << " = " << A - B << endl << endl
         << "Vector product: " << "[ " << A << ", " << B << " ] = " << A * B << endl << endl;

    //тест получения скалярных велечин
    cout << "\n\nEnter new parameters to Vector B: " << endl;
    cin >> B;
    cout << "\n\nTwo-place operations on vectors A and B to obtain scalar quantities\n"
         << "sin: " << sin(A, B) << endl
         << "cos: " << cos(A, B) << endl
         << "Scalar product: (" << A << ", " << B << ") = " <<scalProd(A, B) << endl
         << "The magnitude of the angle in degrees between vectors A and B within [-180; 180]: " << angle(A, B) << endl << endl << endl;

    return 0;
}
