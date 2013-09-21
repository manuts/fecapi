#!/usr/bin/env python
##################################################
# Gnuradio Python Flow Graph
# Title: Top Block
# Generated: Sat Sep 21 19:54:41 2013
##################################################

from fec import ldpc_encoder_bf, ldpc_decoder_fb
from gnuradio import analog
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from grc_gnuradio import wxgui as grc_wxgui
from optparse import OptionParser
import fec
import wx

class top_block(grc_wxgui.top_block_gui):

    def __init__(self):
        grc_wxgui.top_block_gui.__init__(self, title="Top Block")
        _icon_path = "/usr/share/icons/hicolor/32x32/apps/gnuradio-grc.png"
        self.SetIcon(wx.Icon(_icon_path, wx.BITMAP_TYPE_ANY))

        ##################################################
        # Variables
        ##################################################
        self.sigma = sigma = 0.4
        self.max_iterations = max_iterations = 50
        self.alist_file = alist_file = "/home/manu/repos/ldpc/gr-ldpc/python/alist-files/96.3.963"
        self.samp_rate = samp_rate = 32000
        self.encoder = encoder = ldpc_encoder_bf(alist_file)
        self.decoder = decoder = ldpc_decoder_fb(alist_file, sigma, max_iterations)

        ##################################################
        # Blocks
        ##################################################
        self.generic_encoder_0 = fec.encoder(encoder, gr.sizeof_char, gr.sizeof_float)
        self.generic_decoder_0 = fec.decoder(decoder, gr.sizeof_float, gr.sizeof_char)
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, "/home/manu/Downloads/in.flac", False)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1, "/home/manu/Downloads/out.flac")
        self.blocks_file_sink_0.set_unbuffered(False)
        self.blocks_add_xx_0 = blocks.add_vff(1)
        self.analog_noise_source_x_0 = analog.noise_source_f(analog.GR_GAUSSIAN, 0, 0)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_noise_source_x_0, 0), (self.blocks_add_xx_0, 1))
        self.connect((self.blocks_file_source_0, 0), (self.generic_encoder_0, 0))
        self.connect((self.generic_encoder_0, 0), (self.blocks_add_xx_0, 0))
        self.connect((self.blocks_add_xx_0, 0), (self.generic_decoder_0, 0))
        self.connect((self.generic_decoder_0, 0), (self.blocks_file_sink_0, 0))


# QT sink close method reimplementation

    def get_sigma(self):
        return self.sigma

    def set_sigma(self, sigma):
        self.sigma = sigma
        self.set_decoder(ldpc_decoder_fb(self.alist_file, self.sigma, self.max_iterations))

    def get_max_iterations(self):
        return self.max_iterations

    def set_max_iterations(self, max_iterations):
        self.max_iterations = max_iterations
        self.set_decoder(ldpc_decoder_fb(self.alist_file, self.sigma, self.max_iterations))

    def get_alist_file(self):
        return self.alist_file

    def set_alist_file(self, alist_file):
        self.alist_file = alist_file
        self.set_decoder(ldpc_decoder_fb(self.alist_file, self.sigma, self.max_iterations))
        self.set_encoder(ldpc_encoder_bf(self.alist_file))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate

    def get_encoder(self):
        return self.encoder

    def set_encoder(self, encoder):
        self.encoder = encoder

    def get_decoder(self):
        return self.decoder

    def set_decoder(self, decoder):
        self.decoder = decoder

if __name__ == '__main__':
    parser = OptionParser(option_class=eng_option, usage="%prog: [options]")
    (options, args) = parser.parse_args()
    tb = top_block()
    tb.Start(True)
    tb.Wait()

