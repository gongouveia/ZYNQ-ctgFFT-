

// PROJECT HEADERS
#include "complex.h"

// XILINX HEADER
#include "xtime_l.h"
#include "xil_types.h"

// C HEADERS
#include <stdio.h>
#include <stdlib.h>


// @brief - Generates data (VERIFIED)
// @param - acquisition_array - Array where values will be stored
// @param - adc_acquisition_time_us - Difference of time between Acquired Samples
// @return - void
void
print_exectution_time(XTime tStart, XTime tEnd)
{
	    printf("FFT took %.2f us.\n",
	           1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000));
}

// @brief - Prints the valeus of the output array
// @param - array with output values
// @param - number of samples in array size
// @return - void
void
print_output_values(struct complex output_array[], u32 array_size)
{
	for(u32 i = 0; i != array_size; i++)
	{
		printf("%f +%f \n\r", output_array[i].real, output_array[i].imag);

	}
}

// @brief - Prints the modulus o fthe output complex numbers
// @param - array with output values
// @return - void
void
print_output_moudlus_values(struct complex output_array[],u32 array_size)
{
	for(u32 i = 0; i != array_size; i++)
	{
		//printf("%f +%f \n\r", output_array[i].real, output_array[i].imag);
		float magnitude = ComplexModulus(output_array[i]);
		printf("index: %f %f \n\r", i, magnitude);

	}
}
