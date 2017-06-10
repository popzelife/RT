#include "rt.h"

static t_button *init_button(t_button *new)
{
  new = (t_button *)malloc(sizeof(t_button));
  if (new == NULL)
    return (NULL);
  new->surface = NULL;
  new->enabled = true;
  return (new);
}

t_button *lst_new_button(t_button **button, t_butnparam param,
                         SDL_Renderer *render, t_action action)
{
  t_button *new;
  t_button *curs;

  new = NULL;
  new = init_button(new);
  new->rect = *param.rect;
  new->surface = lst_new_surface(&new->surface, surfparam(&new->rect,
                                                          0x88888888, NULL, 0),
                                 render, esdl_clear_surface);
  new->surface->next = param.surface;
  new->string = param.string;
  new->hover = false;
  new->param = action.param;
  new->action = action.f;
  new->i_lst = param.i_lst;
  new->next = NULL;
  if (*button == NULL)
    return (new);
  else
  {
    curs = *button;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*button);
}

void lst_active_button(t_button **button, UINT i_lst, bool active)
{
  t_button *curs;

  curs = *button;
  while (curs && curs->i_lst != i_lst)
    curs = curs->next;
  if (curs)
    curs->enabled = active;
}

void lst_set_button(t_button **button, UINT i_lst, t_action action)
{
  t_button *curs;

  curs = *button;
  while (curs && curs->i_lst != i_lst)
    curs = curs->next;
  if (curs)
  {
    curs->param = action.param;
    curs->action = action.f;
  }
}
