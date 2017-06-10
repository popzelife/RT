#include "rt.h"

void button_close(void *param)
{
  t_rt *rt;

  rt = (void *)param;
  rt->esdl->eng.input->quit = 1;
  rt->esdl->run = 0;
}

void button_minus(void *param)
{
  t_rt *rt;

  rt = (void *)param;
  SDL_MinimizeWindow(rt->esdl->eng.win);
}
