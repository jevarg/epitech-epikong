/*
** draw_image.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 22:30:36 2014 Jean Gravier
** Last update Sat Mar  8 18:25:02 2014 Jean Gravier
*/

#include <SDL/SDL_image.h>
#include "epikong.h"

SDL_Surface	*get_image(char *path)
{
  SDL_Surface	*image;

  image = IMG_Load(path);
  if (!image)
    {
      fprintf(stderr, "Error, IMG_Load: ");
      exit_error(IMG_GetError());
    }
  return (image);
}

void		draw_image(SDL_Surface *surface, char *path, int x, int y)
{
  SDL_Surface	*image;
  SDL_Rect	rect;

  image = IMG_Load(path);
  if (!image)
    {
      fprintf(stderr, "Error, IMG_Load: ");
      exit_error(IMG_GetError());
    }
  rect.x = x;
  rect.y = y;
  rect.w = 0;
  rect.h = 0;
  SDL_BlitSurface(image, NULL, surface, &rect);
  SDL_UpdateRect(surface, x, y, image->w, image->h);
  SDL_FreeSurface(image);
}
