/* determine latitude angle phi-2 */
#ifndef lint
//static const char SCCSID[]="@(#)pj_phi2.c	4.3	93/06/12	GIE	REL";
#endif
#include "proj4.h"
#include <cmath>
#include "proj4_constants.h"

#define TOL 1.0e-10
#define N_ITER 15

	long double
pj_phi2(long double ts, long double e) {
	long double eccnth, Phi, con, dphi;
	int i;

	eccnth = .5 * e;
	Phi = projM_PI_2 - 2. * std::atan (ts);
	i = N_ITER;
	do {
		con = e * std::sin (Phi);
		dphi = projM_PI_2 - 2. * std::atan (ts * std::pow((1. - con) /
		   (1. + con), eccnth)) - Phi;
		Phi += dphi;
	} while ( std::fabs(dphi) > TOL && --i);
/*
	if (i <= 0)
		pj_errno = -18;
*/
	return Phi;
}
