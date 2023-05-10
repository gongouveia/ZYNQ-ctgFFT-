

// XILINX HEADERS
#include "xil_types.h"

#include <math.h>

// PROJECT HEADERS
#include "complex.h"


#define PI 3.14159265


// @brief - Computes the DFT (VERIFIED)
// @param - acquisition_array - Array where initial values are stored
// @param - frequency_domain_array - Array where transformed values will be stored (output valeus)
// @param - time_based_array_size - total number of samples
// @return - void
void
DFT (struct complex* acquisition_array,
		struct complex* frequency_domain_array,
		u32 time_based_array_size)
{

	//xil_printf("Allocation Completed");
	struct complex twiddle;
	struct complex complex_multiplication;
	float angle;
	for(u32 k = 0; k != time_based_array_size; ++k)
	{
		frequency_domain_array[k].real = 0.0;
		frequency_domain_array[k].imag = 0.0;
		for(u32 n = 0; n < time_based_array_size; n++)
		{
			angle = -2*PI*n*k/time_based_array_size;
			twiddle = EulerFormulaComplexAngle(angle);
			complex_multiplication = ComplexMultiply(&acquisition_array[n],&twiddle);
			frequency_domain_array[k] = ComplexAdd(frequency_domain_array[k], complex_multiplication);
		}
	}
}



// @brief - Computes the FFT of the input array with the generalized Culey Tukey algorithm (DFT collumn and row wise)
// @param - input_array - Array where initial values are stored
// @param - output_array - Array where transformed values will be stored (output valeus)
// @param - column_size - number of collumns in intermediate matrix
// @param - row_size - number of rows in intermediate matrix
// @return - void

void
CTG (struct complex* input_array,
		struct complex* output_array,
		u32 column_size, u32 row_size
		)
{
   const u32 time_based_array_size = column_size * row_size;
   struct complex twiddle;
   float angle;

   // Allocate matrix collumn wise
   struct complex columns_matrix[column_size][row_size];
   struct complex columns_matrix_input[column_size][row_size];

   // Allocate matrix rowise
   struct complex rows_matrix[row_size][column_size];
   struct complex rows_matrix_output[row_size][column_size];

   // Reshape input into matrix collumns X rows
   for (u32 i = 0; i != column_size; i++)
   {
      for(u32 j = 0; j != row_size; j++)
      {
    	  columns_matrix_input[i][j] = input_array[column_size*j + i];
      }
   }

   // Compute N1 DFTs of length N2
   for (u32 i = 0; i != column_size; i++)
   {
      DFT(columns_matrix_input[i],columns_matrix[i], row_size);
   }

   // Multiply by the twiddle factors
   for(u32 i = 0; i != column_size; i++)
   {
      for (u32 j = 0; j != row_size; j++)
      {
         angle = -2.0*PI*i*j/time_based_array_size;
         twiddle = EulerFormulaComplexAngle(angle);
         rows_matrix[j][i] = ComplexMultiply(&twiddle,&columns_matrix[i][j]);
      }
   }

   // Compute N2 DFTs of length N1
   for (int i = 0; i != row_size; i++)
   {
      DFT(rows_matrix[i],rows_matrix_output[i], column_size);
   }

   // Converts Matrix to Array output
   for(u32 i = 0; i != column_size; i++)
   {
      for (u32 j = 0; j != row_size; j++)
      {
    	  output_array[row_size*i + j] = rows_matrix_output[j][i];
      }
   }
}


// @brief - Computes the FFT of the input array with the generalized Culey Tukey algorithm (FFT collumn and row wise)
//          This method is done for square matrixs but can be changed for any input matrix
// @param - input_array - Array where initial values are stored
// @param - output_array - Array where transformed values will be stored (output values)
// @param - bigger_matrix_row_size - number of rows in principal FFT matrix
// @param - smaller_matrix_row_size - number of rows in intermediate FFT matrix
// @return - void
void
CTG_Better (struct complex* input_array,
		struct complex* output_array,
		u32 bigger_matrix_row_size,
		u32 smaller_matrix_row_size)
{
   const u32 time_based_array_size = bigger_matrix_row_size * bigger_matrix_row_size;
   struct complex twiddle;
   float angle;
   // Allocate matrix collumn wise
   struct complex columns_matrix_input[bigger_matrix_row_size][bigger_matrix_row_size];
   struct complex columns_matrix_output[bigger_matrix_row_size][bigger_matrix_row_size];
   // Allocate matrix rowise
   struct complex rows_matrix[bigger_matrix_row_size][bigger_matrix_row_size];
   struct complex rows_matrix_output[bigger_matrix_row_size][bigger_matrix_row_size];

   // Reshape input into matrix collumns X rows
   for (u32 i = 0; i != bigger_matrix_row_size; i++)
   {
      for(u32 j = 0; j != bigger_matrix_row_size; j++)
      {
    	  columns_matrix_input[i][j] = input_array[bigger_matrix_row_size*j + i];
      }
   }

   // Compute N1 DFTs of length N2
   for (u32 i = 0; i != bigger_matrix_row_size; i++)
   {
      //DFT(columns_matrix_input[i],columns_matrix[i], row_size);
	   CTG (columns_matrix_input[i], columns_matrix_output[i],  smaller_matrix_row_size,  smaller_matrix_row_size);
   }

   // Multiply by the twiddle factors
   for(u32 i = 0; i != bigger_matrix_row_size; i++)
   {
      for (u32 j = 0; j != bigger_matrix_row_size; j++)
      {
         angle = -2.0*PI*i*j/time_based_array_size;
         twiddle = EulerFormulaComplexAngle(angle);
         rows_matrix[j][i] = ComplexMultiply(&twiddle,&columns_matrix_output[i][j]);
      }
   }

   // Compute N2 DFTs of length N1
   for (int i = 0; i != bigger_matrix_row_size; i++)
   {
	   CTG (rows_matrix[i], rows_matrix_output[i],  smaller_matrix_row_size,  smaller_matrix_row_size);
      //DFT(rows_matrix[i],rows_matrix_output[i], column_size);
   }

   // Converts Matrix to Array output
   for(u32 i = 0; i != bigger_matrix_row_size; i++)
   {
      for (u32 j = 0; j != bigger_matrix_row_size; j++)
      {
    	  output_array[bigger_matrix_row_size*i + j] = rows_matrix_output[j][i];
      }
   }

}
