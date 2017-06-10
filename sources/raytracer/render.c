#include "rt.h"

void render(t_rt *rt)
{
  t_thread *th_curs;
  t_iter *it_curs;
  int *tab[2];
  int i;

  esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
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
