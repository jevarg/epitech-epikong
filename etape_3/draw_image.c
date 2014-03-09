/*
** draw_image.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 20:53:23 2014 Jean Gravier
** Last update Sun Mar  9 19:49:38 2014 Jean Gravier
*/

#include <SDL/SDL_image.h>
#include "epikong.h"

void		blit_part(SDL_Surface *surface, SDL_Rect *rect, char *path)
{
  SDL_Surface	*image;

  image = get_image(path);
  SDL_BlitSurface(image, rect, surface, rect);
  SDL_FreeSurface(image);
}

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
  SDL_Flip(surface);
  SDL_FreeSurface(image);
}

void		draw_image_only(SDL_Surface *surface, char *path, int x, int y)
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
  SDL_FreeSurface(image);
}

void		draw_image_menu_part(SDL_Surface *surface, char *path, int x, int y)
{
  SDL_Surface	*image;
  SDL_Rect	rect;
  SDL_Rect	srcrect;

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
  srcrect.x = srcrect.x * -1;
  srcrect.y = 0;
  if ((x -= 500) < 0)
    x *= -1;
  srcrect.w = x;
  srcrect.h = 350;
  SDL_BlitSurface(image, &srcrect, surface, &rect);
  SDL_FreeSurface(image);
}
