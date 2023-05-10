

// PROJECT HEADERS
#include "complex.h"

// XILINX HEADER
#include "xtime_l.h"
#include "xil_types.h"

// C HEADERS
#include <stdio.h>
#include <stdlib.h>

void
print_exectution_time(XTime tStart, XTime tEnd)
{
	    printf("FFT took %.2f us.\n",
	           1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000));
}


void
print_output_values(struct complex output_array[], u32 array_size)
{
	for(u32 i = 0; i != array_size; i++)
	{
		printf("%f +%f \n\r", output_array[i].real, output_array[i].imag);
	}
}

