#include "rt.h"

void init_filter(t_filtermatrice *m, t_filtervalue *f, t_matrixf t, t_rt *rt)
{
  m->matricewidth = t.size;
  m->matriceheigth = t.size;
  m->factor = 1.0 / t.factor;
  m->bias = 0.0;
  f->y = -1;
  f->pixels = (Uint32 *)rt->sr_view->pixels;
}

void reset_rgb(t_filtermatrice *m)
{
  m->r = 0.0;
  m->g = 0.0;
  m->b = 0.0;
  m->filtery = -1;
}

void calc_filter(t_filtermatrice *m, t_filtervalue *f, t_matrixf t, t_rt *rt)
{
  m->imagex = (f->x - m->matricewidth / 2 + m->filterx + rt->sr_view->w) %
              rt->sr_view->w;
  m->imagey = (f->y - m->matriceheigth / 2 + m->filtery + rt->sr_view->h) %
              rt->sr_view->h;
  f->pixel = f->pixels[m->imagey * rt->sr_view->w + m->imagex];
  f->b = f->pixel >> 16 & 0xFF;
  f->g = f->pixel >> 8 & 0xFF;
  f->r = f->pixel & 0xFF;
  m->b += f->b * t.matrice[m->filtery * (t.size + 1) + m->filterx];
  m->g += f->g * t.matrice[m->filtery * (t.size + 1) + m->filterx];
  m->r += f->r * t.matrice[m->filtery * (t.size + 1) + m->filterx];
}
