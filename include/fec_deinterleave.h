/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_FEC_DEINTERLEAVE_H
#define INCLUDED_FEC_DEINTERLEAVE_H

#include <fec_api.h>
#include <gnuradio/block.h>

class fec_deinterleave;
typedef boost::shared_ptr<fec_deinterleave> fec_deinterleave_sptr;

FEC_API fec_deinterleave_sptr fec_make_deinterleave (size_t itemsize, unsigned int blocksize);

/*!
 * \brief deinterleave signal input to N coding blocks
 */
class FEC_API fec_deinterleave : public gr::block
{
    friend fec_deinterleave_sptr fec_make_deinterleave (size_t itemsize, unsigned int blocksize);

    unsigned int d_current_output;
    size_t d_itemsize;
    unsigned int d_blocksize;
    unsigned int d_noutputs;
    fec_deinterleave (size_t itemsize, unsigned int blocksize);

public:
  ~fec_deinterleave ();

  int general_work (int noutput_items,
		    gr_vector_int& ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);

  bool check_topology (int ninputs, int noutputs);

};

#endif /* INCLUDED_FEC_DEINTERLEAVE_H */
