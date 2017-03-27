#include "rt.h"

t_rgb	wood(t_v3d inter, double coef)
{
	double	coefnoise;
	int	z;
	double	v;

	coef /= 10;
	coefnoise = fabs(noise(inter.x * coef, inter.y * coef, inter.z * coef));
	v = 20 * coefnoise;
	z = (int)v;
	v -= z;
	if (v < 0.2)
		return (rgb_create(254, 136, 77));
	else if (v < 0.4)
		return (rgb_create(129, 99, 29));
	else if (v < 0.6)
		return (rgb_create(110, 107, 28));
	else if (v < 0.8)
		return (rgb_create(118, 84, 23));
	else
		return (rgb_create(141, 102, 28));
}
