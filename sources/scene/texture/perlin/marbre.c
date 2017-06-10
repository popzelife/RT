#include "rt.h"

t_rgb		marbre(t_v3d inter, double mult)
{
	int	level;
	double	noisecoef;

	level = 0;
	noisecoef = 0;
	while (++level < 10)
	{
		noisecoef += (1.0 / level) * fabs(noise(level * 0.05 * inter.x * \
		mult, level * 0.05 * inter.y * mult, level * 0.05 * \
		inter.z * mult));
	}
	noisecoef = 0.5 * sinf((inter.x * mult + inter.y * mult) * 0.5 + \
			noisecoef) + 0.5;
	if (noisecoef < 0.3)
		return (rgb_create(12, 12, 12));
	if (noisecoef < 0.6)
		return (rgb_create(130, 130, 130));
	else
		return (rgb_create(255, 255, 255));
}
