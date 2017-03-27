# define XX noise->x
# define YY noise->y
# define ZZ noise->z
# define U noise->u
# define V noise->v
# define W noise->w
# define A1 noise->a
# define B1 noise->b
# define AA1 noise->aa
# define AB1 noise->ab
# define BA1 noise->ba
# define BB1 noise->bb
# define PER noise->per

typedef struct		s_noise
{
	int		per[512];
	int		x;
	int		y;
	int		z;
	double		u;
	double		v;
	double		w;
	int		a;
	int		b;
	int		aa;
	int		bb;
	int		ab;
	int		ba;
} 			t_noise;

/*
** Tous les trucs utiles au Perlin
*/

void	fill_material_in_case(t_mat *mat);
void	coeff(double d, double alpha, t_v3d *norm, \
	t_v3d inter);
double	noise(double x, double y, double z);
void	fill_xyz(t_noise *noise, double x, double y, double z);
void	fill_uvw(t_noise *noise, double x, double y, double z);
void	fill_baba(t_noise *a);
double	noise_to_ret(t_noise *a, double b, double c, double d);
double	fade(double a);
double	lerp(double x, double y, double z);
double	grad(int a, double x, double y, double z);
int	modify_color_for_tex(char *tex, t_v3d vec, t_light *datas, \
	double c);
t_rgb	wood(t_v3d inter, double coef);
t_rgb	marbre(t_v3d inter, double mult);
t_rgb	damier(double l, t_v3d i, t_rgb col);
void	water(double d, t_v3d *n, t_v3d inter, t_v3d dir);
t_rgb	 random_noise(double coef, t_v3d vec, t_rgb rgb);
