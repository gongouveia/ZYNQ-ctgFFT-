
#ifndef OUTPUT_H__
#define OUTPUT_H__


// XILINX HEADER
#include "xtime_l.h"
#include "xil_types.h"

// PROJECT HEADERS
#include "complex.h"

void
print_exectution_time(XTime tStart, XTime tEnd);


void
print_output_values(struct complex output_array[], u32 array_size);



#endif // OUTPUT_H__
