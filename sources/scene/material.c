#include "rt.h"

t_mat *new_material(t_vec3 albedo, double t, t_texture *text)
{
  t_mat *m;

  m = malloc(sizeof(t_mat));
  m->albedo = albedo;
  m->t = t;
  m->m_text = text;
  return (m);
}

bool scatter_none(const t_ray ray, const t_hit param,
                  t_vec3 *attenuation, t_ray *scattered)
{
  (void)ray;
  (void)param;
  (void)attenuation;
  (void)scattered;
  return (false);
}
