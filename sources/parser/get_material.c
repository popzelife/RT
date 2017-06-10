#include "rt.h"

int xml_to_texture(char *line, uchar *i)
{
  if (!ft_choose_texture(line))
  {
    ft_printf("Parse ERROR - This value: %s is not a texture\n", line);
    return (0);
  }
  *i = ft_choose_texture(line);
  return (1);
}

int xml_to_path(char *line, char **path)
{
  if (!ft_check_filename(line))
  {
    ft_printf("Parse ERROR - This value: %s is not a valid path\n", line);
    return (0);
  }
  *path = strdup(line);
  return (1);
}

uchar choose_material(char *line)
{
  if (ft_strcmp(line, "lambert") == 0)
    return (MAT_LAMBERT);
  if (ft_strcmp(line, "metal") == 0)
    return (MAT_METAL);
  if (ft_strcmp(line, "dielectric") == 0)
    return (MAT_DIELECT);
  if (ft_strcmp(line, "diffuse light") == 0)
    return (MAT_DIFF_LIGHT);
  return (0);
}

int xml_to_material(char *line, uchar *i)
{
  if (!choose_material(line))
  {
    ft_printf("Parse ERROR - This value: %s is not a texture\n", line);
    return (0);
  }
  *i = choose_material(line);
  return (1);
}
