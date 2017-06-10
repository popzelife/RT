#include "rt.h"

int *ft_tab2(const int x, const int y)
{
  int *xy;

  xy = (int *)malloc(2 * sizeof(int));
  xy[0] = x;
  xy[1] = y;
  return (xy);
}

void		settab2(int *xy, const int x, const int y)
{
	xy[0] = x;
	xy[1] = y;
}

int min(const int a, const int b)
{
  if (a < b)
    return (a);
  return (b);
}

int max(const int a, const int b)
{
  if (a > b)
    return (a);
  return (b);
}

char *ft_uitoa_32bit(UINT lvalue)
{
  int x;
  char *str;

  x = 31;
  str = ft_strdup("00000000000000000000000000000000");
  if (lvalue == 0)
    return (str);
  while (lvalue > 0)
  {
    if (lvalue % 2 >= 10)
      str[x] = lvalue % 2 - 10 + 'A';
    else
      str[x] = lvalue % 2 + '0';
    lvalue /= 2;
    --x;
  }
  return (str);
}

char *ft_strtolower(char *s)
{
  int i;

  i = 0;
  while (s[i])
  {
    s[i] = ft_tolower(s[i]);
    ++i;
  }
  return (s);
}

char *ft_ltrim(char *s)
{
  while (ft_isspace(*s) != 0)
    s++;
  return (s);
}

char *ft_rtrim(char *s)
{
  char *back;

  back = s + ft_strlen(s);
  while (ft_isspace(*--back) != 0)
    *(back + 1) = '\0';
  return (s);
}

char *ft_trim(char *s)
{
  return (ft_rtrim(ft_ltrim(s)));
}

int ft_isnumerical(char *s)
{
  int c;
  int m;
  int d;
  int i;

  i = 0;
  d = 0;
  c = 0;
  m = 0;
  while (s[i] != '\0')
  {
    while (s[i] == ' ' || s[i] == '\t')
      ++i;
    if (s[i] && (s[i] == '-' || s[i] == '+') && m < 1 && !d && !c)
      ++m;
    else if (s[i] && s[i] == '.' && c < 1 && ft_isdigit(s[i + 1]) && d)
      ++c;
    else if (s[i] && ft_isdigit(s[i]))
      ++d;
    else
      return (0);
    ++i;
  }
  return (d);
}

char *ft_strccstr(char *dst, char *src, char start, char end)
{
  int i;

  while (*src != start && *src)
    src++;
  if (*src == start)
    src++;
  i = 0;
  while (src[i] != end && src[i])
    ++i;
  dst = ft_memalloc(i + 1);
  dst = ft_strncpy(dst, src, i);
  return (dst);
}

char *ft_strcstr(char *dst, char *src, char end)
{
  int i;

  i = 0;
  while (src[i] != end && src[i])
    ++i;
  dst = ft_memalloc(i + 1);
  dst = ft_strncpy(dst, src, i);
  return (dst);
}

int ft_strloopstr(const char *s1, const char *s2)
{
  size_t i;
  size_t j;
  size_t len;

  len = ft_strlen(s2);
  i = 0;
  while (s1[i])
  {
    j = 0;
    while (s1[i] != s2[j] && s1[i])
      ++i;
    while (s1[i] == s2[j] && s1[i] && s2[j])
    {
      ++i;
      ++j;
      if (j == len)
        return (0);
    }
  }
  return (-1);
}

int ft_strcmptab(char *line, char **tab, int size)
{
  int i;

  i = 0;
  while (i < size)
  {
    if ((ft_strloopstr(line, tab[i])) == 0)
      return (i);
    ++i;
  }
  return (-1);
}
