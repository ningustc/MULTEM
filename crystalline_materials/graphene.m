function [Crys3D, lx, ly, lz] = graphene(n, a, rms)
CrysPar.na = n;
CrysPar.nb = round(3*n/sqrt(3));
CrysPar.nc = 0;
CrysPar.a = 3*a;
CrysPar.b = sqrt(3)*a;
CrysPar.c = 2;
CrysPar.nuLayer = 1;
occ = 1;
region = 0;
charge = 0;
% C = 6
% Z charge x y z rms3d occupancy region charge
CrysPar.uLayer(1).atoms = [6, 0.0, 0.0, 0.0, rms, occ, region, charge;...
6, 1/3, 0.0, 0.0, rms, occ, region, charge; 6, 1/2, 1/2, 0.0, rms, occ, region, charge; 6, 5/6, 1/2, 0.0, rms, occ, region, charge];

Crys3D = il_crystal_by_lays(CrysPar);
lx = CrysPar.a*CrysPar.na;
ly = CrysPar.b*CrysPar.nb;
lz = 0.0;