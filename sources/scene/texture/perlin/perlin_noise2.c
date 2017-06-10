#include "rt.h"

void	fill_xyz(t_noise *noise, double x, double y, double z)
{
	XX = (int)floor(x) & 255;
	YY = (int)floor(y) & 255;
	ZZ = (int)floor(z) & 255;
}

void	fill_uvw(t_noise *noise, double x, double y, double z)
{
	U = fade(x);
	V = fade(y);
	W = fade(z);
}

void	fill_baba(t_noise *noise)
{
	A1 = PER[XX] + YY;
	AA1 = PER[A1] + ZZ;
	AB1 = PER[A1 + 1] + ZZ;
	B1 = PER[XX + 1] + YY;
	BA1 = PER[B1] + ZZ;
	BB1 = PER[B1 + 1] + ZZ;
}

double	noise_to_ret(t_noise *noise, double x, double y, double z)
{
	return (lerp(W, lerp(V, lerp(U, grad(PER[AA1], x, y, z),
						grad(PER[BA1], x - 1, y, z)),
					lerp(U, grad(PER[AB1], x, y - 1, z),
						grad(PER[BB1], x - 1, y - 1, z))),
				lerp(V, lerp(U, grad(PER[AA1 + 1], x, y, z - 1),
						grad(PER[BA1 + 1], x - 1, y, z - 1)),
					lerp(U, grad(PER[AB1 + 1], x, y - 1, z - 1),
						grad(PER[BB1 + 1], x - 1, y - 1, z - 1)))));
}
