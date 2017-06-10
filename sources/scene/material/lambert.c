#include "rt.h"

bool scatter_lambertian(const t_ray ray, const t_hit param,
                        t_vec3 *attenuation, t_ray *scattered)
{
  t_vec3 target;

  (void)ray;
  target = v3_add_vec_(v3_add_vec_(param.pos, param.normal),
                       random_in_unit_sphere());
  *scattered = new_ray(param.pos, v3_sub_vec_(target, param.pos));
  texture_it(param, attenuation);
  return (true);
}
