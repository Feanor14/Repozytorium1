//  A simple and practical way to show the format of the IEEE standard
for binary floating-point numbers (IEEE 754) is to use a union, as shown in the following example:

#include <iostream>
#include <basetsd.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

union FloatNum //Here the tag name (FloatNum) is redundant.
 {
   float fx;//4 bytes variable
   long  lx;//4 bytes variable
 }fn;

union DoubleNum
 {
   double dx;  //8 bytes variable
   LONG64 lx;  //8 bytes variable
 }dn;

union LongDoubleNum
 {
   long double dx;  //12 bytes variable
   long  lx[3]; // 3 * 4 bytes variable
 }ldn;

int main()
{
    fn.fx = -118.6253433; //variable assignment declaration statement
    //show size of float
    cout << "\nsize of float = " << dec << sizeof(fn.fx) << endl;
    cout << setprecision(10) << fn.fx << " = 0x" << hex << fn.lx << endl;

    dn.dx =  112.6255678;  //assign value to a variable
    //show size of double
    cout << "\nsize of double = " << dec << sizeof(dn.dx) << endl;
    cout << dn.dx <<"  = 0x" << hex << dn.lx << endl;

    ldn.dx = -12.61256125;  //assign value to a variable
    //show size of long double
    cout << "\nsize of long double = " << dec << sizeof(ldn.dx) << endl;
    cout << setprecision(10) << ldn.dx << " = 0x" << hex << ldn.lx[2] << ldn.lx[1] << ldn.lx[0] << endl;
    return 0;
}

