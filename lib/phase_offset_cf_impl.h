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

#ifndef INCLUDED_MEU_PHASE_OFFSET_CF_IMPL_H
#define INCLUDED_MEU_PHASE_OFFSET_CF_IMPL_H

#include <meu/phase_offset_cf.h>


namespace gr {
  namespace meu {

    class phase_offset_cf_impl : public phase_offset_cf
    {
     private:
      std::vector<gr_complex> d_channel_state;


     public:
      phase_offset_cf_impl(const std::string& lengthtagname);
      ~phase_offset_cf_impl();

     float get_ref_phase(const gr_complex &sample);

      int calculate_output_stream_length(const gr_vector_int &ninput_items);
      // Where all the action really happens
      int work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace meu
} // namespace gr

#endif /* INCLUDED_MEU_PHASE_OFFSET_CF_IMPL_H */

