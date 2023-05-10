#ifndef ALGORITHM_H__
#define ALGORITHM_H__


// PROJECT HEADERS
#include "complex.h"

// XILINX HEADERS
#include "xil_types.h"


void
DFT (struct complex* acquisition_array,
		struct complex* frequency_domain_array,
		u32 time_based_array_size);


void
CTG (struct complex* input_array,
		struct complex* output_array,
		u32 column_size, u32 row_size);


void
CTG_Better (struct complex* input_array,
		struct complex* output_array,
		u32 bigger_matrix_row_size,
		u32 smaller_matrix_row_size);


#endif // ALGORITHM_H__
