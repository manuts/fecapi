/* -*- c++ -*- */

%{
#include "ldpc_decoder_fb.h"
%}

generic_decoder_sptr ldpc_make_decoder_fb(const char * alist_file,
            float sigma, int max_iterations);

class ldpc_decoder_fb {
    public:
    ldpc_decoder_fb( const char * alist_file,
            float sigma, int max_iterations);
    ~ldpc_decoder_fb();
    int get_input_size();
    int get_output_size();
    int get_niterations();
};
