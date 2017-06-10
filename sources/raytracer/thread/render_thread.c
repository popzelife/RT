#include "rt.h"

void join_render(t_rt *rt)
{
  t_thread *th_curs;
  int i;

  i = 0;
  th_curs = rt->t;
  while (i++ < rt->m_thread)
  {
    join_thread(th_curs);
    th_curs = th_curs->next;
  }
  ft_printf("Render pass # %3d/%3d %20s\r", (rt->iter->s == 1 ? rt->iter->s : rt->iter->s - 1), ALIASING, " ");
}

void render_low(t_rt *rt)
{
  t_thread *th_curs;
  t_iter *it_curs;
  int *tab[2];
  int i;

  i = 0;
  th_curs = rt->t;
  it_curs = rt->iter;
  while (i++ < rt->m_thread)
  {
    tab[0] = &(it_curs->x);
    tab[1] = &(it_curs->y);
    set_thread(th_curs, rt, tab, &(it_curs->s));
    th_curs = th_curs->next;
    it_curs = it_curs->next;
  }
  join_render(rt);
}

void thread_render(t_tharg *arg)
{
  if (*(arg->s) == 0)
    raytracer_lowres(arg);
  else
  {
    raytracer_highres(arg);
    multisampling(arg);
  }
  set_thread_pos(arg);
  pthread_exit(NULL);
}

void thread_render_low(t_tharg *arg)
{
  if (*(arg->s) == 0)
    raytracer_lowres(arg);
  set_thread_pos(arg);
  pthread_exit(NULL);
}
