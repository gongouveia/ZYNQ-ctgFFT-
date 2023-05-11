
// XILINX HEADERS
#include "platform.h"
#include "xil_printf.h"
#include "xil_types.h"
#include <sleep.h>

// C HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// PROJECT HEADERS
#include "complex.h"
#include "acquisition.h"
#include "algorithm.h"
#include "output.h"

#include "xtime_l.h"
#include <xsysmon.h>

#define PI 3.14159265





// Difference of time between Acquired Samples
static const u32 ADC_ACQUISITION_US = 100;

// Declaration of the total samples to acquire and transform in it's frequency domain
static const u32 COLLUMNS = 100;
static const u32 ROWS = 100;
static const u32 RX_BUFFER_SIZE = COLLUMNS * ROWS;


// value only applied to the CTG algorithm in the 10000 points case
static const u32 ROWS_CTG_ALGO_INTERMEDIATE_MATRIX = 10;


XSysMon xadc;
XSysMon_Config *xadc_config;



int main()
{

    init_platform ();
    XTime tStart, tEnd;


    while(1)
    {

		//xil_printf("aux  %d \n\r ", aux);

    	// ALllocates memory arrays
    	struct complex acquisition_buffer [RX_BUFFER_SIZE];
    	struct complex fft_output [RX_BUFFER_SIZE];
		//xil_printf("Memory Allocated: %d !!\n\r", RX_BUFFER_SIZE);


		// Acquires data
    	GenerateData(acquisition_buffer,RX_BUFFER_SIZE, ADC_ACQUISITION_US);
		//xil_printf("FT Started : !!\n\r");

		// Computes FFT and computes execution time
	    XTime_GetTime(&tStart);

			//DFT(acquisition_buffer,fft_output, RX_BUFFER_SIZE);
			//CTG(acquisition_buffer, fft_output, COLLUMNS , ROWS );
			CTG_Better (acquisition_buffer, fft_output, ROWS, ROWS_CTG_ALGO_INTERMEDIATE_MATRIX);

	    XTime_GetTime(&tEnd);


	    // Prints the execution time
	    print_exectution_time( tStart, tEnd);
	    // Prints the output values of the FFT
	    print_output_values(fft_output, RX_BUFFER_SIZE);



		//xil_printf("<=============x===========>\n\r");
    }
    cleanup_platform();

    return 0;
}

