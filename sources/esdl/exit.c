#include "rt.h"

void esdl_exit(t_esdl *esdl)
{
  SDL_DestroyRenderer(esdl->eng.render);
  SDL_DestroyWindow(esdl->eng.win);
  if (esdl->ttf)
    TTF_Quit();
  SDL_Quit();
}
