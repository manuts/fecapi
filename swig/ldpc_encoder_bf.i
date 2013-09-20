/* -*- c++ -*- */

%{
#include "ldpc_encoder_bf.h"
%}

generic_encoder_sptr ldpc_make_encoder_bf(const char * alist_file);

class ldpc_encoder_bf {
    public:
    ldpc_encoder_bf( const char * alist_file );
    ~ldpc_encoder_bf();
    int get_input_size();
    int get_output_size();
};
