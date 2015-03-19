/*
 * This file is part of MULTEM.
 * Copyright 2014 Ivan Lobato <Ivanlh20@gmail.com>
 *
 * MULTEM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MULTEM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MULTEM. If not, see <http://www.gnu.org/licenses/>.
 */

#include "hMT_General_CPU.h"
#include <mex.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[ ]) 
{
	int n, nx, ny, shift;
	double dx, dy, Radius;
	double *f;
 
	ny = (int)mxGetScalar(prhs[0]);
	nx = (int)mxGetScalar(prhs[1]);
	dy = mxGetScalar(prhs[2]);
	dx = mxGetScalar(prhs[3]);
	Radius = mxGetScalar(prhs[4]);
	n = (int)mxGetScalar(prhs[5]);
	shift = (int)mxGetScalar(prhs[6]);

	plhs[0] = mxCreateDoubleMatrix(ny, nx, mxREAL);
	f = mxGetPr(plhs[0]);

	f_getButterworth_Filter_2D(ny, nx, dy, dx, Radius, n, 1, shift, f);
}