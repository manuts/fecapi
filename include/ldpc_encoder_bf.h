#ifndef INCLUDED_LDPC_ENCODER_BF_H
#define INCLUDED_LDPC_ENCODER_BF_H

#include <fec_encoder.h>
#include <cldpc.h>
#include <alist.h>

FEC_API generic_encoder_sptr
ldpc_make_encoder_bf ( const char * alist_file );

class FEC_API ldpc_encoder_bf : public generic_encoder
{
    friend generic_encoder_sptr
    ldpc_make_encoder_bf( const char * alist_file );

    private:
    alist d_list;
    cldpc d_code;
    int K;
    int N;

    public:
    ldpc_encoder_bf ( const char * alist_file );
    void generic_work(void *inBuffer, void *outBuffer);
    int get_output_size();
    int get_input_size();
    ~ldpc_encoder_bf();

};

#endif // INCLUDED_LDPC_ENCODER_BF_H
