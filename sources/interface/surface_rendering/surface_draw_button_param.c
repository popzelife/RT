#include "rt.h"

void draw_button_param1(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(
      *(rt->r_menu), esdl_rect(105, 310, MENU_RX - 105, 30));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM1),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM1, false);
}

void draw_button_param2(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 31,
                                                    MENU_RX - 105, 29));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM2),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM2, false);
}

void draw_button_param3(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 61,
                                                    MENU_RX - 105, 29));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM3),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM3, false);
}

void draw_button_param4(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 91,
                                                    MENU_RX - 105, 29));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM4),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM4, false);
}

void draw_button_param5(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 121,
                                                    MENU_RX - 105, 29));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM5),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM5, false);
}

void draw_button_param6(t_rt *rt, t_menu *m, int *i)
{
  m->rect = esdl_fuse_rect(*(rt->r_menu), esdl_rect(105, 310 + 151,
                                                    MENU_RX - 105, 29));
  rt->panel.lst_button = lst_new_button(
      &rt->panel.lst_button,
      butnparam(
          lst_new_string(&m->nullstring, strparam("", rt->panel.word1, i, 0),
                         rt->esdl->eng.render, esdl_render_blendedtext),
          lst_new_surface(&m->nullsurf, surfparam(&m->rect, 0x00000000, NULL, 0),
                          rt->esdl->eng.render, esdl_clear_surface),
          &m->rect, BTN_PARAM6),
      rt->esdl->eng.render, actionparam(NULL, NULL));
  lst_active_button(&rt->panel.lst_button, BTN_PARAM6, false);
}
