/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <gnuradio/expj.h>
#include "phase_offset_cf_impl.h"

static const pmt::pmt_t CHAN_TAPS_KEY = pmt::mp("ofdm_sync_chan_taps");

namespace gr {
  namespace meu {

    phase_offset_cf::sptr
    phase_offset_cf::make(const std::string &lengthtagname){
      return gnuradio::get_initial_sptr(new phase_offset_cf_impl(lengthtagname));
    }
    phase_offset_cf_impl::phase_offset_cf_impl(const std::string &lengthtagname)
    : gr::tagged_stream_block("phase_offset_cf",
      gr::io_signature::make(1, 1, sizeof(gr_complex)),
      gr::io_signature::make(1, 1, sizeof(float)),lengthtagname), 
    d_channel_state(64, gr_complex(1, 0))
    {
     // if (tsb_key.empty()) 
     // {
     //   throw std::invalid_argument("Specify a TSB tag!");
     //  }
     // set_relative_rate(1.0);
      set_tag_propagation_policy(TPP_DONT);
    }

    phase_offset_cf_impl::~phase_offset_cf_impl()
    {
    }
 /*
      void
      phase_offset_cf_impl::parse_length_tags(
        const std::vector<std::vector<tag_t> > &tags,
        gr_vector_int &n_input_items_reqd
        ) {
        if (tags[0].key == pmt::string_to_symbol(d_length_tag_key_str)) 
        {
          n_input_items_reqd[0] = pmt::to_long(tags[0].value);
        }
      }
*/
    float
    phase_offset_cf_impl::get_ref_phase(const gr_complex &sample)
    {
       /* since phase_correction is a complex number uses the value of imag and real components to check in which quadrant it is */
      if (sample.imag() >= 0 and sample.real() >= 0) {
        return 0;
      }
      else if (sample.imag() >= 0 and sample.real() < 0) {
        return (1.5708);
      }
      else if (sample.imag() < 0 and sample.real() < 0) {
        return (3.14159);
      }
      else if (sample.imag() < 0 and sample.real() >= 0) {
        return (4.71239);
      }

    }

    int
    phase_offset_cf_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      //return (ninput_items[0]);
    	return 400 ;
    }

    int
    phase_offset_cf_impl::work (int noutput_items,
     gr_vector_int &ninput_items,
     gr_vector_const_void_star &input_items,
     gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      float *out = (float *) output_items[0];
      //gr_complex *out = (gr_complex *) output_items[0];
      //long packet_length = ninput_items[0]; // the exact number of this PDU, all of these items will be consumed 
      long packet_length = 400 ;

      std::vector<tag_t> tags;
      get_tags_in_window(tags, 0, 0, 1);
      for (unsigned i = 0; i < tags.size(); i++) {
        if (pmt::symbol_to_string(tags[i].key) == "ofdm_sync_chan_taps") {
          d_channel_state = pmt::c32vector_elements(tags[i].value);
        }
      }

      for (int i = 0; i < packet_length; i++) {
       out[i]= get_ref_phase(d_channel_state[6]);
       //out[i]= d_channel_state[6];
     }

      // Tell runtime system how many output items we produced.
     return packet_length;
   }

  } /* namespace meu */
} /* namespace gr */

