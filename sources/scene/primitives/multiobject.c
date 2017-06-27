#include "rt.h"

t_multiobj *new_multiobject(int count, ...)
{
  t_multiobj *m;
  va_list valist;
  register int i;

  if (!count ||
      !(m = malloc(sizeof(t_multiobj))) ||
      !(m->objs = malloc(sizeof(t_obj) * count)))
    return (NULL);
  for (i = 0; i < count; ++i)
  {
    m->objs[i] = va_arg(valist, t_obj);
    if (!m->objs[i].p_obj)
      return (NULL);
  }
  m->sizeof_multiobj = count;
  m->type_obj = m->objs[0].type_obj;
  m->p_obj = &(m->objs[0]);
  m->hit = m->objs[0].hit;
  m->p_mat = m->objs[0].p_mat;
  va_end(valist);
  return (m);
}

bool push_obj_to_multi(t_multiobj *m, t_obj obj)
{
  if (!obj.p_obj || !m || !m->sizeof_multiobj ||
      !(m->objs = (t_obj *)realloc(
            m->objs, (m->sizeof_multiobj + 1) * sizeof(t_obj))))
    return (false);
  m->objs[m->sizeof_multiobj] = obj;
  m->sizeof_multiobj += 1;
  return (true);
}

bool hit_multiobject(void *obj, const t_ray ray, const double t[2],
                     t_hit *param)
{
  t_multiobj *multi;
  bool hit_anything;
  double closest_so_far[2];
  register int i;

  multi = (t_multiobj *)obj;
  hit_anything = false;
  closest_so_far[0] = t[0];
  closest_so_far[1] = t[1];
  for (i = 0; i < multi->sizeof_multiobj; ++i)
  {
    if (multi->objs[i].hit(multi->objs[i].p_obj,
                           ray, closest_so_far, param))
    {
      hit_anything = true;
      closest_so_far[1] = param->t;
      multi->p_mat = multi->objs[i].p_mat;
      multi->type_obj = multi->objs[i].type_obj;
      multi->p_obj = multi->objs[i].p_obj;
    }
  }
  return (hit_anything);
}
