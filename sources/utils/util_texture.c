#include "rt.h"

uint32_t getpixel(SDL_Surface *surface, int x, int y)
{
  int bpp;
  uint8_t *p;

  bpp = surface->format->BytesPerPixel;
  p = (uint8_t *)surface->pixels + y * surface->pitch + x * bpp;
  if (bpp == 1)
    return (*p);
  if (bpp == 2)
    return (*(uint16_t *)p);
  if (bpp == 3)
  {
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return (p[0] << 16 | p[1] << 8 | p[2]);
    else
      return (p[0] | p[1] << 8 | p[2] << 16);
  }
  if (bpp == 4)
    return (*(uint32_t *)p);
  return (0);
}
