/*
** draw_map.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 20:58:06 2014 Jean Gravier
** Last update Fri Mar  7 23:13:54 2014 Jean Gravier
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#define BLOCK_SIZE 30

void		draw_map(SDL_Surface *surface)
{
  int		i;

  i = 3;
  while (i <= 7)
    {
      draw_image(surface, "data/ladder.png", (surface->w / 2) - BLOCK_SIZE, BLOCK_SIZE * i++);
    }
}
