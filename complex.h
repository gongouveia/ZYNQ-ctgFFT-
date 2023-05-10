

#ifndef complex_H__
#define complex_H__

// XILINX headers
#include <xil_types.h>

// XILINX HEADERS
#include <math.h>
#include <xil_types.h>


// complex number representation
struct complex
{
	float real;
	float imag;
};

// Sum two complex values
struct complex
ComplexAdd (struct complex value1, struct complex value2);

// Multiply two complex values
struct complex
ComplexMultiply ( struct complex* left, struct  complex* right);


// Computes complex exponential
struct complex
EulerFormulaComplexAngle (float exponent);

// Divide two complex values
struct complex
ComplexDivide (struct complex left, struct complex right);

// Compute magnitude of the complex number
float
ComplexModulus(struct complex complex_number);

float
cosine(float x, u32 number_of_factors);

float
sine(float x, u32 number_of_factors);


#endif // complex_H__
