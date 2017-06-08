#include "rt.h"

double	alpha(double n, double v1, double v2)
{
	return ((n - v1) / (v2 - v1));
}

double	beta(double n, double v1, double v2)
{
	return ((v2 - n) / (v2 - v1));
}

t_rgb	new_col(t_rgb r1, t_rgb r2, double alpha, double beta)
{
	t_rgb a;

	a.r = r1.r * alpha + r2.r * beta;
	a.g = r1.g * alpha + r2.g * beta;
	a.b = r1.b * alpha + r2.b * beta;
	return (a);
}

t_rgb	random_noise(double coef, t_v3d vec, t_rgb rgb)
{
	double	n;
	t_4d	v;
	t_rgb	a;
	t_rgb	b;
	t_rgb	c;

	v.a = 0.0;
	a = rgb;
	rgb_s_mult(&a, 2);
	rgb_reg(&a);
	v.b = 0.3;
	b = rgb_create(15, rgb.g, rgb.b);
	v.c = 0.6;
	c = rgb_create(rgb.r, 15, rgb.b);
	v.d = 1;
	n = noise(vec.x * coef, vec.y * coef, vec.z * coef);
	if (n < v.b)
		return (new_col(a, b, alpha(n, v.a, v.b), beta(n, v.a, v.b)));
	if (n < v.c)
		return (new_col(b, c, alpha(n, v.b, v.c), beta(n, v.b, v.c)));
	if (n < v.d)
		return (new_col(c, rgb, alpha(n, v.c, v.d), beta(n, v.c, v.d)));
	return (rgb);
}
