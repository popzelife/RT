#include "rt.h"

void draw_view(t_rt *rt)
{
  rt->r_view = malloc(sizeof(SDL_Rect));
  SDL_GetWindowSize(rt->win_temp, &rt->r_view->w, &rt->r_view->h);
  rt->r_view->x = 0;
  rt->r_view->y = TILE_RY;
  rt->r_view->w -= MENU_RX;
  rt->r_view->h -= TILE_RY;
  rt->sr_view = esdl_create_surface(rt->r_view->w, rt->r_view->h);
  rt->s_process = esdl_create_surface(rt->r_view->w, rt->r_view->h);
  rt->render = true;
}

void udpate_view(t_rt *rt)
{
  t_iter *curs_iter;
  int x;
  int y;

  curs_iter = rt->iter;
  x = 0;
  y = 0;
  while (curs_iter != NULL)
  {
    curs_iter->s = 0;
    curs_iter->x = x;
    curs_iter->y = y;
    x += RT_SUBXY;
    if (x > rt->r_view->w * MSAMP)
    {
      x = 0;
      y += RT_SUBXY;
    }
    curs_iter = curs_iter->next;
  }
}

void param_view_high(t_rt *rt)
{
  t_iter *curs_iter;
  int x;
  int y;

  curs_iter = rt->iter;
  x = 0;
  y = 0;
  while (curs_iter != NULL)
  {
    curs_iter->s = 1;
    curs_iter->x = x;
    curs_iter->y = y;
    x += RT_SUBXY;
    if (x > rt->r_view->w * MSAMP)
    {
      x = 0;
      y += RT_SUBXY;
    }
    curs_iter = curs_iter->next;
  }
}
