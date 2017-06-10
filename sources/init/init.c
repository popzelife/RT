#include "rt.h"

void init_rand(t_rt *rt)
{
  time_t t;

  srand((unsigned)time(&t));
  random_seed(rt->seed, 7);
}

void init_rt(t_rt *rt)
{
  rt->esdl = malloc(sizeof(t_esdl));
  if (esdl_init(rt->esdl, LOAD_RX, LOAD_RY, API_NAME) == -1 ||
      esdl_init_ttf(rt->esdl) == -1)
  {
    esdl_exit(rt->esdl);
  }
  init_loader(rt);
  progress_load(rt, 1);
  render_load(rt);
  SDL_Delay(1000);
}

void init_screen_buffer(t_rt *rt)
{
  int i;
  int j;

  rt->tab = (t_vec3 **)malloc(rt->r_view->w * MSAMP *
                              sizeof(t_vec3 *));
  i = 0;
  while (i < rt->r_view->w * MSAMP)
  {
    rt->tab[i] = (t_vec3 *)malloc(rt->r_view->h * MSAMP *
                                  sizeof(t_vec3));
    j = 0;
    while (j < rt->r_view->h * MSAMP)
    {
      rt->tab[i][j] = v3_(0., 0., 0.);
      ++j;
    }
    ++i;
  }
}

void init_multithread(t_rt *rt)
{
  int i;
  int x;
  int y;

  rt->m_thread = 32;
  rt->iter = NULL;
  i = 0;
  x = 0;
  y = 0;
  while (i++ < rt->m_thread)
  {
    rt->iter = lst_new_iter(&(rt->iter), 1, x, y);
    x += RT_SUBXY;
    if (x > rt->r_view->w * MSAMP)
    {
      x = 0;
      y += RT_SUBXY;
    }
  }
  rt->limit_iter = ALIASING;
  rt->t = NULL;
  i = 0;
  while (i++ < rt->m_thread)
    rt->t = lst_new_thread(&(rt->t));
}
