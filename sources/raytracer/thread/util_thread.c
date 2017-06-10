#include "rt.h"

void join_thread(t_thread *t)
{
  int ret;

  if ((ret = pthread_join(t->thread, NULL)) != 0)
  {
    ft_dprintf(2, "RT error %d - pthread_join failed\n", ret);
    exit(-1);
  }
}

void set_thread(t_thread *t, t_rt *rt, int *i[2], int *s)
{
  int ret;

  t->arg.rt = rt;
  t->arg.scene = rt->this_scene;
  t->arg.i = i[0];
  t->arg.j = i[1];
  t->arg.tab = rt->tab;
  t->arg.s = s;
  if ((ret = pthread_create(&t->thread, NULL, (void *)thread_render,
                            (void *)&t->arg)) != 0)
  {
    ft_dprintf(2, "RT error %d - pthread_create failed at %s\n", ret,
               __FUNCTION__);
    exit(-1);
  }
}

void set_thread_low(t_thread *t, t_rt *rt, int *i[2], int *s)
{
  int ret;

  t->arg.rt = rt;
  t->arg.scene = rt->this_scene;
  t->arg.i = i[0];
  t->arg.j = i[1];
  t->arg.tab = rt->tab;
  t->arg.s = s;
  if ((ret = pthread_create(&t->thread, NULL, (void *)thread_render,
                            (void *)&t->arg)) != 0)
  {
    ft_dprintf(2, "RT error %d - pthread_create failed at %s\n", ret,
               __FUNCTION__);
    exit(-1);
  }
}

void set_thread_pos(t_tharg *arg)
{
  *(arg->i) += RT_SUBXY * arg->rt->m_thread;
  if (*(arg->i) >= arg->rt->r_view->w * MSAMP)
  {
    *(arg->i) -= arg->rt->r_view->w * MSAMP;
    *(arg->i) -= (*(arg->i) % RT_SUBXY);
    *(arg->j) += RT_SUBXY;
  }
  if (*(arg->j) > arg->rt->r_view->h * MSAMP)
  {
    ++(*(arg->s));
    *(arg->j) -= arg->rt->r_view->h * MSAMP;
    *(arg->j) -= (*(arg->j) % RT_SUBXY);
    *(arg->j) -= RT_SUBXY;
  }
}

void end_thread(t_tharg *arg)
{
  arg->rt->suspend = true;
}
