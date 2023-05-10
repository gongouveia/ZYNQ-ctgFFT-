



#ifndef ACQUISITION_H__
#define ACQUISITION_H__


// PROJECT HEADERS
#include "complex.h"

// XILINX HEADERS
#include "xil_types.h"



// @brief - Generates data (VERIFIED)
// @param - acquisition_array - Array where values will be stored
// @param - adc_acquisition_time_us - Difference of time between Acquired Samples
// @return - void
void
GenerateData (struct complex* acquisition_array,u32 matrix_size, u32 adc_acquisition_time_us);



#endif // ACQUISITION_H__
