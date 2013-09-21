#include <ldpc_decoder_fb.h>

generic_decoder_sptr
ldpc_make_decoder_fb( const char * alist_file, float sigma,
        int max_iterations)
{
    return generic_decoder_sptr(new ldpc_decoder_fb(alist_file,
                sigma, max_iterations));
}

ldpc_decoder_fb::ldpc_decoder_fb ( const char * alist_file,
        float sigma, int max_iterations)
    : generic_decoder("ldpc_decoder_fb")
{
    d_list.read(alist_file);
    d_code.set_alist(d_list);
    d_spa.set_alist_sigma(d_list, sigma);
    K = d_code.dimension();
    N = d_code.get_N();
    d_spa.set_K(K);
    d_spa.set_max_iterations(max_iterations);
    rx.resize(N);
}

ldpc_decoder_fb::~ldpc_decoder_fb ()
{
}

int
ldpc_decoder_fb::get_output_size()
{
    return K;
}

int
ldpc_decoder_fb::get_input_size()
{
    return N;
}

int
ldpc_decoder_fb::get_niterations()
{
    return n_iterations;
}

void
ldpc_decoder_fb::generic_work(void *inBuffer, void *outBuffer)
{
    const float *in = (const float *) inBuffer;
    char *out = (char *) outBuffer;

        // Do <+signal processing+>
    for ( int i = 0; i < N; i++ ) {
        rx[i] = in[i];
    }
    estimate = d_spa.decode(rx, &n_iterations);
    data = d_code.get_systematic_bits(estimate);
    for ( int i = 0; i < K; i++ ) {
        out[i] = data[i];
    }
}
