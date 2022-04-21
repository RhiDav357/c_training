#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Complex Complex_t;

struct Complex
{
    double real;
    double imag;
};

void Complex_IncrementBy(Complex_t *pValue, Complex_t operand)
{
    pValue->real += operand.real;
    pValue->imag += operand.imag;
}

Complex_t Compex_Conjugate(Complex_t value)
{
    value.imag = -value.imag;

    return value;
}

int main(int argc, char *argv[])
{
    Complex_t z1 = {3.3, 3.5};
    Complex_t z2, z3;

    z2.real = 1.1;
    z2.imag = 1.1;

    cout << "z1 = " << z1.real << " + " << z1.imag << "i \n";
    cout << "z2 = " << z2.real << " + " << z2.imag << "i \n";

    // z1 += z2
    Complex_IncrementBy(&z1, z2);
    cout << "Incremented z1 = " << z1.real << " + " << z1.imag << "i \n";

    z3 = Compex_Conjugate(z1);
    cout << "z3 = " << z3.real << " + " << z3.imag << "i \n";

    z1.real -= 10.5;

    cout << "z1 - 10.5 = " << z1.real << " + " << z1.imag << "i \n";
}