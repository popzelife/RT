#include "rt.h"

void bo_texture(t_scene *s, t_parser *p, char *line)
{
  char *value;
  uchar type;

  value = NULL;
  if (!xml_get_value(line, &value))
  {
    ft_printf("Parse %s ERROR - Value not found at line %d: '%s'\n",
              __FUNCTION__, p->l, line);
    exit(-1);
  }
  if (!xml_to_texture(value, &type))
  {
    ft_printf("Parse %s ERROR - Something went wrong while assigning value:"
              " '%s' on material[%d].texture.type\n",
              __FUNCTION__, value, p->i_obj);
    exit(-1);
  }
  s->obj[p->i_obj].p_mat->m_text = new_texture(type, NULL);
  free(value);
}

void bo_texture_filename(t_scene *s, t_parser *p, char *line)
{
  char *value;
  char *path;

  value = NULL;
  path = NULL;
  if (!xml_get_value(line, &value))
  {
    ft_printf("Parse %s ERROR - Value not found at line %d: '%s'\n",
              __FUNCTION__, p->l, line);
    exit(-1);
  }
  if (!xml_to_path(value, &path))
  {
    ft_printf("Parse %s ERROR - Something went wrong while assigning value:"
              " '%s' on material[%d].texture.path\n",
              __FUNCTION__, value, p->i_obj);
    exit(-1);
  }
  free(s->obj[p->i_obj].p_mat->m_text);
  s->obj[p->i_obj].p_mat->m_text = new_texture(TEXT_IMAGE, path);
  free(path);
  free(value);
}
