/*
	 Copyright (C) 2003 Paul Brossier

	 This program is free software; you can redistribute it and/or modify
	 it under the terms of the GNU General Public License as published by
	 the Free Software Foundation; either version 2 of the License, or
	 (at your option) any later version.

	 This program is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 GNU General Public License for more details.

	 You should have received a copy of the GNU General Public License
	 along with this program; if not, write to the Free Software
	 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef BIQUAD_H
#define BIQUAD_H

/** \file 

  Second order Infinite Impulse Response filter

  This file implements a normalised biquad filter (second order IIR):
 
  \f$ y[n] = b_0 x[n] + b_1 x[n-1] + b_2 x[n-2] - a_1 y[n-1] - a_2 y[n-2] \f$

  The filtfilt version runs the filter twice, forward and backward, to
  compensate the phase shifting of the forward operation.

  See also <a href="http://en.wikipedia.org/wiki/Digital_biquad_filter">Digital
  biquad filter</a> on wikipedia.

*/

#ifdef __cplusplus
extern "C" {
#endif

/** set coefficients of a biquad filter

  \param b0 forward filter coefficient
  \param b1 forward filter coefficient
  \param b2 forward filter coefficient
  \param a1 feedback filter coefficient
  \param a2 feedback filter coefficient

*/
uint_t
aubio_filter_set_biquad (aubio_filter_t * f, lsmp_t b0, lsmp_t b1, lsmp_t b2,
    lsmp_t a1, lsmp_t a2);

/** create new biquad filter

  \param b0 forward filter coefficient
  \param b1 forward filter coefficient
  \param b2 forward filter coefficient
  \param a1 feedback filter coefficient
  \param a2 feedback filter coefficient

*/
aubio_filter_t *
new_aubio_filter_biquad (lsmp_t b0, lsmp_t b1, lsmp_t b2, lsmp_t a1, lsmp_t a2,
    uint_t channels);

#ifdef __cplusplus
}
#endif

#endif /*BIQUAD_H*/
