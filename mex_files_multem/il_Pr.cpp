/*
 * This file is part of MULTEM.
 * Copyright 2017 Ivan Lobato <Ivanlh20@gmail.com>
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
 * along with MULTEM. If not, see <http:// www.gnu.org/licenses/>.
 */

#include "types.cuh"
#include "atom_cal.hpp"
#include "atomic_data.hpp"

#include <mex.h>
#include "matlab_mex.cuh"

using mt::rmatrix_r;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	auto potential_type = mx_get_scalar<mt::ePotential_Type>(prhs[0]);
	auto Z = mx_get_scalar<int>(prhs[1]);
	auto charge = mx_get_scalar<int>(prhs[2]);
	auto r = mx_get_matrix<rmatrix_r>(prhs[3]);

	auto Pr = mx_create_matrix<rmatrix_r>(r.rows, r.cols, plhs[0]);
	auto dPr = mx_create_matrix<rmatrix_r>(r.rows, r.cols, plhs[1]);

	mt::Atom_Type<double, mt::e_host> atom_type;
	mt::Atomic_Data atomic_data(potential_type);
	atomic_data.To_atom_type_CPU(Z, mt::c_Vrl, mt::c_nR, 0.0, atom_type);

	mt::Atom_Cal<double> atom_cal;
	atom_cal.Set_Atom_Type(potential_type, charge, &atom_type);
	atom_cal.Pr_dPr(r.m_size, r.real, Pr.real, dPr.real);
}