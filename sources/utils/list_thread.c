#include "rt.h"

t_iter *lst_new_iter(t_iter **iter, int i, int x, int y)
{
  t_iter *new;
  t_iter *curs;

  new = NULL;
  new = (t_iter *)malloc(sizeof(t_iter));
  if (new == NULL)
    return (NULL);
  new->s = i;
  new->x = x;
  new->y = y;
  new->next = NULL;
  if (*iter == NULL)
    return (new);
  else
  {
    curs = *iter;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*iter);
}

t_thread *lst_new_thread(t_thread **thread)
{
  t_thread *new;
  t_thread *curs;

  new = NULL;
  new = (t_thread *)malloc(sizeof(t_thread));
  if (new == NULL)
    return (NULL);
  new->next = NULL;
  if (*thread == NULL)
    return (new);
  else
  {
    curs = *thread;
    while (curs->next != NULL)
      curs = curs->next;
    curs->next = new;
  }
  return (*thread);
}
