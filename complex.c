// PROJECT HEADERS
#include "complex.h"
#include <math.h>

// XILINX HEADERS
#include <xil_types.h>


// Sum two complex values
struct complex
ComplexAdd (struct complex left, struct complex right)
{
    struct complex result;
    result.real = left.real + right.real;
    result.imag = left.imag + right.imag;
    return result;
}

// Multiply two complex values
struct complex
ComplexMultiply ( struct complex* left, struct  complex* right)
{
    struct complex result;
    result.real = left->real*right->real - left->imag*right->imag;
    result.imag = left->real*right->imag + left->imag*right->real;
    return result;
}

// Divide two complex values
struct complex
ComplexDivide(struct complex left, struct complex right)
{
    struct complex result;
    float numerator_real = left.real*right.real + left.imag*right.imag;
    float numerator_imag = left.imag*right.real - left.real*right.imag;
    float denominator    = right.real*right.real + right.imag*right.imag;
    result.real = numerator_real/denominator;
    result.imag = numerator_imag/denominator;

    return result;
}


// Compute magnitude of the complex number
float
ComplexModulus(struct complex complex_number)
{
    float modulus = sqrt(pow(complex_number.real, 2) + pow(complex_number.imag, 2));
    return modulus;
}

// Computes complex exponential  e^(i*theta)
struct complex
EulerFormulaComplexAngle (float exponent)
{
    struct complex result;
    //u32 number_of_taylor_factors = 4;
    result.real =  cosf(exponent);
    result.imag =  sinf(exponent);
    return result;
}




