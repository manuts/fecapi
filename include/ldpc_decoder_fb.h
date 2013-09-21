#ifndef INCLUDED_LDPC_DECODER_FB_H
#define INCLUDED_LDPC_DECODER_FB_H

#include <fec_decoder.h>
#include <cldpc.h>
#include <alist.h>
#include <awgn_bp.h>
#include <vector>

FEC_API generic_decoder_sptr
ldpc_make_decoder_fb ( const char * alist_file, float sigma,
        int max_iterations);

class FEC_API ldpc_decoder_fb : public generic_decoder
{
    friend generic_decoder_sptr
    ldpc_make_decoder_fb( const char * alist_file, float sigma,
            int max_iterations);

    private:
    alist d_list;
    cldpc d_code;
    awgn_bp d_spa;
    int K;
    int N;
    int n_iterations;
    std::vector<float> rx;
    std::vector<char> estimate, data;

    public:
    ldpc_decoder_fb ( const char * alist_file, float sigma,
            int max_iterations);
    void generic_work(void *inBuffer, void *outBuffer);
    int get_output_size();
    int get_input_size();
    int get_niterations();
    ~ldpc_decoder_fb();

};

#endif // INCLUDED_LDPC_DECODER_FB_H
