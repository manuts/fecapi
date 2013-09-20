#include <ldpc_encoder_bf.h>
#include <vector>

generic_encoder_sptr
ldpc_make_encoder_bf( const char * alist_file )
{
    return generic_encoder_sptr(new ldpc_encoder_bf(alist_file));
}

ldpc_encoder_bf::ldpc_encoder_bf ( const char * alist_file )
{
    d_list.read(alist_file);
    d_code.set_alist(d_list);
    K = d_code.dimension();
    N = d_code.get_N();
}

ldpc_encoder_bf::~ldpc_encoder_bf ()
{
}

int
ldpc_encoder_bf::get_output_size()
{
    return N;
}

int
ldpc_encoder_bf::get_input_size()
{
    return K;
}

void
ldpc_encoder_bf::generic_work(void *inBuffer, void *outBuffer)
{
    const char *in = (const char *) inBuffer;
    float *out = (float *) outBuffer;
    std::vector<char> data, code;
    data.resize(K);

    for ( int i = 0; i < K; i++ ) {
        data[i] = in[i];
    }

    code = d_code.encode(data);

    for ( int i = 0; i < N; i++ ) {
        if ( code[i] == char(0) ) {
            out[i] = 1.0;
        }
        else {
            out[i] = -1.0;
        }
    }
}
