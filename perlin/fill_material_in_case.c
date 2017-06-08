#include "rt.h"

#ifndef FILL_MAT
# define FILL_MAT
# define AMB mat->ambient
# define DIFFU mat->diffuse
# define SPEC mat->specular
# define SHI mat->shine
#endif

void	fill_material_in_case(t_mat *mat)
{
	AMB = ft_rand_double(0.0, 0.1);
	DIFFU = ft_rand_double(0.0, 0.2);
	SPEC = ft_rand_double(0.0, 1);
	SHI = (double)ft_rand_int(5000, 2);
}
