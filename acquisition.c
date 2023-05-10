

// XILINX HEADERS
#include "xil_types.h"
#include <sleep.h>


// PROJECT HEADERS
#include "complex.h"


// @brief - Generates data (VERIFIED)
// @param - acquisition_array - Array where values will be stored
// @param - adc_acquisition_time_us - Difference of time between Acquired Samples
// @return - void
void
GenerateData (struct complex* acquisition_array,
		u32 matrix_size,
		u32 adc_acquisition_time_us)
{
	/* Init inputs */
	for (int i=0; i < matrix_size; i++)
	{
	  acquisition_array[i].real = (float) i;
	  acquisition_array[i].imag = 0.0;
	  usleep(adc_acquisition_time_us);
	}
}
