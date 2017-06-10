#include "rt.h"

t_texture *new_texture(const uchar type_texture, char *filename)
{
  t_texture *t;

  t = malloc(sizeof(t_texture));
  t->type_texture = type_texture;
  t->filename = NULL;
  if (filename != NULL && type_texture == TEXT_IMAGE)
  {
    t->filename = ft_strdup(filename);
    t->data = IMG_Load(filename);
    if (t->data == NULL)
      t->type_texture = TEXT_NONE;
  }
  return (t);
}

void texture_it(const t_hit param, t_vec3 *attenuation)
{
  if (param.material->m_text)
  {
    if (param.material->m_text->type_texture == TEXT_IMAGE &&
        param.material->m_text->filename != NULL)
    {
      if (param.type_obj == OBJ_SPHERE)
        return (texture_sphere(param, attenuation));
    }
    else if (param.material->m_text->type_texture == TEXT_CHCKBOARD)
      return (texture_checkboard(param.pos, attenuation));
    else if (param.material->m_text->type_texture == TEXT_LINEX)
      return (texture_linex(param.pos, attenuation));
    else if (param.material->m_text->type_texture == TEXT_LINEY)
      return (texture_liney(param.pos, attenuation));
    else if (param.material->m_text->type_texture == TEXT_RAINBOW)
      return (texture_rainbow(param.pos, attenuation));
  }
  *attenuation = param.material->albedo;
}
