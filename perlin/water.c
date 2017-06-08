#include "rt.h"

void	water(double d, t_v3d *norm, t_v3d inter, t_v3d dir)
{
	t_v3d tall;
	t_v3d ret;

	if (fabs(dir.y) > fabs(dir.x) && fabs(dir.y) > fabs(dir.z))
	tall = v3d(norm->x + inter.x, 50 * norm->y + 100 * inter.y, norm->z + \
	inter.z);
	else if (fabs(dir.x) > fabs(dir.y) && fabs(dir.x) > fabs(dir.z))
	tall = v3d(50 * norm->x + 100 * inter.x, norm->y + inter.y, norm->z + \
	inter.z);
	else if (fabs(dir.z) > fabs(dir.x) && fabs(dir.z) > fabs(dir.y))
	tall = v3d(norm->x + inter.x, norm->y + inter.y, 50 * norm->z + \
	100 * inter.z);
	ret = v3d(noise(tall.x - d, tall.y, tall.z) - noise(tall.x + d, tall.y, \
	tall.z), noise(tall.x, tall.y - d, tall.z) - noise(tall.x, tall.y \
	+ d, tall.z), noise(tall.x, tall.y, tall.z - d) - noise(tall.x, \
	tall.y, tall.z + d));
	norm->x += ret.x;
	norm->y += ret.y;
	norm->z += ret.z;
}
