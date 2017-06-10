#include "rt.h"

t_surfparam surfparam(SDL_Rect *rect, int color, void *param, int i)
{
  t_surfparam p;

  p.rect = rect;
  p.color = color;
  p.param = param;
  p.i_lst = i;
  return (p);
}

t_strparam strparam(char *string, t_font font, int xy[2], int i)
{
  t_strparam p;

  p.string = string;
  p.font = font;
  p.xy[0] = xy[0];
  p.xy[1] = xy[1];
  p.i_lst = i;
  return (p);
}

t_butnparam butnparam(t_string *string, t_surface *surface, SDL_Rect *rect,
                      int i)
{
  t_butnparam p;

  p.string = string;
  p.surface = surface;
  p.rect = rect;
  p.i_lst = i;
  return (p);
}

t_action actionparam(void *param, void(f)(void *))
{
  t_action p;

  p.param = param;
  p.f = f;
  return (p);
}

t_imgparam new_imgparam(char *name)
{
  t_imgparam p;

  p.path = name;
  return (p);
}

void set_imgparam(t_imgparam *param, char *name)
{
  param->path = name;
}
