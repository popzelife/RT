#include "rt.h"

uchar ft_choose_texture(char *line)
{
  if (ft_strcmp(line, "checkboard") == 0)
    return (TEXT_CHCKBOARD);
  if (ft_strcmp(line, "liney") == 0)
    return (TEXT_LINEY);
  if (ft_strcmp(line, "linex") == 0)
    return (TEXT_LINEX);
  if (ft_strcmp(line, "rainbow") == 0)
    return (TEXT_RAINBOW);
  if (ft_strcmp(line, "image") == 0)
    return (TEXT_IMAGE);
  return (0);
}

int ft_check_filename(char *line)
{
  int fd;

  fd = open(line, O_RDONLY);
  if (fd > 0)
  {
    close(fd);
    return (1);
  }
  return (0);
}
