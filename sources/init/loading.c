#include "rt.h"

void loading(t_rt *rt)
{
  rt->win_temp = SDL_CreateWindow(" ", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, WIN_RX, WIN_RY, SDL_WINDOW_HIDDEN);
  draw_view(rt);
  rt->sizeof_scn = 1;
  rt->scene = (t_scene *)malloc(rt->sizeof_scn * sizeof(t_scene));
  rt->scene[0] = init_scene(rt);
  rt->this_scene = &rt->scene[0];
  draw_menu(rt);
  progress_load(rt, 20);
  render_load(rt);
  SDL_DestroyWindow(rt->win_temp);
}

void render_load(t_rt *rt)
{
  SDL_RenderClear(rt->esdl->eng.render);
  SDL_RenderCopy(rt->esdl->eng.render, rt->tx_load, NULL, NULL);
  SDL_RenderCopy(rt->esdl->eng.render, rt->tx_bar, NULL, &rt->r_bar);
  SDL_RenderCopy(rt->esdl->eng.render, rt->tx_progress, NULL,
                 &rt->r_progress);
  SDL_RenderPresent(rt->esdl->eng.render);
}

void progress_load(t_rt *rt, int percent)
{
  rt->r_progress.w += rt->r_bar.w * percent / 100;
  esdl_clear_surface(rt->sr_bar, NULL, CBAR, NULL);
  esdl_clear_surface(rt->sr_progress, NULL, CPROGRESS, NULL);
  SDL_DestroyTexture(rt->tx_bar);
  SDL_DestroyTexture(rt->tx_progress);
  rt->tx_bar = SDL_CreateTextureFromSurface(rt->esdl->eng.render,
                                            rt->sr_bar);
  rt->tx_progress = SDL_CreateTextureFromSurface(rt->esdl->eng.render,
                                                 rt->sr_progress);
}

void init_loader(t_rt *rt)
{
  SDL_Rect r_load;

  rt->sr_logo = SDL_LoadBMP("image/Logo.bmp");
  SDL_SetWindowIcon(rt->esdl->eng.win, rt->sr_logo);
  SDL_SetWindowBordered(rt->esdl->eng.win, false);
  SDL_FreeSurface(rt->sr_logo);
  rt->tx_load = esdl_load_texture(rt->esdl->eng.render, "image/Loader.bmp",
                                  &r_load.w, &r_load.h);
  rt->r_bar.w = LOAD_RX;
  rt->r_bar.x = 0;
  rt->r_bar.y = LOADBAR_RX;
  rt->r_bar.h = LOADBAR_RY;
  rt->r_progress = rt->r_bar;
  rt->r_progress.y += 3;
  rt->r_progress.h -= 6;
  rt->sr_bar = esdl_create_surface(rt->r_bar.w, rt->r_bar.h);
  rt->sr_progress = esdl_create_surface(rt->r_progress.w, rt->r_progress.h);
  rt->r_progress.w = 0;
}
