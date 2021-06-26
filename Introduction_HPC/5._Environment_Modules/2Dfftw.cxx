//2Dfftw.cpp
//2 dimensional complex-to-real inverse FFT test.
//Produces a 256 x 256 real-valued matrix
#include <fstream>
#include <iostream>
#include <complex>
#include <fftw3.h>

int main(int argc, char** argv)
{
    int FFTSIZE = 256;

    std::complex<double>* input_array;
    std::complex<double>* output_array;

   // input_array = new std::complex<double>[FFTSIZE * FFTSIZE];
    //output_array = new double[FFTSIZE * FFTSIZE];
    output_array = (std::complex<double>*)fftw_alloc_complex(FFTSIZE*FFTSIZE);
    input_array = (std::complex<double>*)fftw_alloc_complex(FFTSIZE * FFTSIZE);

    for(int i = 0; i < FFTSIZE * FFTSIZE; i++) input_array[i] = 0;

    input_array[50000]   = std::complex<double>(100, 0);
    input_array[10000]  = std::complex<double>(100, 0);
    input_array[16000]  = std::complex<double>(100, 0);
    input_array[48000]  = std::complex<double>(100, 0);
    input_array[32000] = std::complex<double>(100, 0);

    fftw_plan p = fftw_plan_dft_2d(FFTSIZE, FFTSIZE, (fftw_complex*)input_array, (fftw_complex*)output_array, FFTW_BACKWARD, FFTW_DESTROY_INPUT | FFTW_ESTIMATE);
    fftw_execute(p);

    std::ofstream InputDump("input.txt");
    for(int j = 0; j < FFTSIZE; j++)
    {
        for(int i = 0; i < FFTSIZE; i++)
        {
            InputDump << " " << input_array[j * FFTSIZE + i].real();
        }
        InputDump << std::endl;
    }
    InputDump.close();

    std::ofstream OutputDump("output.txt");
    for(int j = 0; j < FFTSIZE; j++)
    {
        for(int i = 0; i < FFTSIZE; i++)
        {
            OutputDump << " " << output_array[j * FFTSIZE + i].real();
        }
        OutputDump << std::endl;
    }
    OutputDump.close();

}

