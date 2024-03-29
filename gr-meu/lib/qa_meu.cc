/*
 * Copyright 2012 Free Software Foundation, Inc.
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

/*
 * This class gathers together all the test cases for the gr-filter
 * directory into a single test suite.  As you create new test cases,
 * add them here.
 */

#include "qa_meu.h"
#include "qa_qpsk_demod_adapt_cb.h"
#include "qa_qpsk_modulator_adapt_cb.h"
#include "qa_ofdm_frame_equalizer_adapt_vcvc.h"
#include "qa_phase_finder_vci.h"

CppUnit::TestSuite *
qa_meu::suite()
{
  CppUnit::TestSuite *s = new CppUnit::TestSuite("meu");
  s->addTest(gr::meu::qa_qpsk_demod_adapt_cb::suite());
  s->addTest(gr::meu::qa_qpsk_modulator_adapt_cb::suite());
  s->addTest(gr::meu::qa_ofdm_frame_equalizer_adapt_vcvc::suite());
  s->addTest(gr::meu::qa_phase_finder_vci::suite());

  return s;
}
