#include "rt.h"

void	coeff(double density, double alpha, t_v3d *norm, t_v3d inter)
{
	t_v3d	tmp2;
	t_v3d	noisecoef;
	double	tt;
	double	temp;

	noisecoef.x = noise(alpha * inter.x, alpha * inter.y, alpha * inter.z);
	noisecoef.y = noise(alpha * inter.y, alpha * inter.z, alpha * inter.x);
	noisecoef.z = noise(alpha * inter.z, alpha * inter.x, alpha * inter.y);
	tmp2.x = (1.0f - density) * norm->x + density * noisecoef.x;
	tmp2.y = (1.0f - density) * norm->y + density * noisecoef.y;
	tmp2.z = (1.0f - density) * norm->z + density * noisecoef.z;
	*norm = unit_v3d(tmp2);
	tt = length_v3d(tmp2);
	temp = carre(tt);
	if (temp == 0.0f)
		return ;
	else
	{
		tt = 1 / tt;
		norm->x = tmp2.x * tt;
		norm->y = tmp2.y * tt;
		norm->z = tmp2.z * tt;
		unit_v3d(*norm);
	}
}
