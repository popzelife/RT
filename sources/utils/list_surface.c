#include "rt.h"

t_surface *lst_new_surface(t_surface **surface, t_surfparam param,
                           SDL_Renderer *render, void(f)(SDL_Surface *, const SDL_Rect *,
                                                         const int, void *))
{
  t_surface *new;
  t_surface *curs;

  new = NULL;
  new = (t_surface *)malloc(sizeof(t_surface));
  if (new == NULL)
    return (NULL);
  new->rect = esdl_copy_rect(*param.rect);
  new->surf = esdl_create_surface(new->rect->w, new->rect->h);
  f(new->surf, new->rect, param.color, param.param);
  new->text = SDL_CreateTextureFromSurface(render, new->surf);
  SDL_FreeSurface(new->surf);
  new->next = NULL;
  if (*surface == NULL)
    return (new);
  else
  {
    curs = *surface;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*surface);
}

t_surface *lst_new_image(t_surface **surface, t_surfparam param,
                         SDL_Renderer *render, SDL_Texture *(f)(SDL_Renderer *, const char *,
                                                                int *, int *))
{
  t_surface *new;
  t_surface *curs;
  t_imgparam *p;

  p = (t_imgparam *)param.param;
  new = NULL;
  new = (t_surface *)malloc(sizeof(t_surface));
  if (new == NULL)
    return (NULL);
  new->rect = esdl_copy_rect(*param.rect);
  new->surf = NULL;
  new->text = f(render, p->path, &new->rect->w, &new->rect->h);
  new->next = NULL;
  if (*surface == NULL)
    return (new);
  else
  {
    curs = *surface;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*surface);
}

t_string *lst_new_string(t_string **string, t_strparam param,
                         SDL_Renderer *render, t_text(f)(char *, t_font, int[2],
                                                         SDL_Renderer *))
{
  t_string *new;
  t_string *curs;

  new = NULL;
  new = (t_string *)malloc(sizeof(t_string));
  if (new == NULL)
    return (NULL);
  new->text = f(param.string, param.font, param.xy, render);
  new->next = NULL;
  if (*string == NULL)
    return (new);
  else
  {
    curs = *string;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*string);
}

void lst_set_surface(t_surface **surface, t_surfparam param,
                     SDL_Renderer *render, void(f)(SDL_Surface *, const SDL_Rect *,
                                                   const int, void *))
{
  t_surface *curs;
  int i;

  curs = *surface;
  i = 0;
  while (i++ < param.i_lst)
    curs = curs->next;
  if (param.rect != NULL)
  {
    free(curs->rect);
    curs->rect = esdl_copy_rect(*(param.rect));
  }
  curs->surf = esdl_create_surface(curs->rect->w, curs->rect->h);
  f(curs->surf, curs->rect, param.color, param.param);
  curs->text = SDL_CreateTextureFromSurface(render, curs->surf);
  SDL_FreeSurface(curs->surf);
}

void lst_set_string(t_string **string, t_strparam param,
                    SDL_Renderer *render, t_text(f)(char *, t_font, int[2],
                                                    SDL_Renderer *))
{
  t_string *curs;
  int i;

  curs = *string;
  i = 0;
  while (i++ < param.i_lst)
    curs = curs->next;
  curs->text = f(param.string, param.font, param.xy, render);
}
