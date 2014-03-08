/*
** draw_map.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 20:58:06 2014 Jean Gravier
** Last update Sat Mar  8 17:48:49 2014 Jean Gravier
*/

#include <stdlib.h>
#include <stdio.h>
#include "epikong.h"

void	char_to_sprite(char c, int x, int y, SDL_Surface *surface)
{
  if (c == 'w')
    draw_image(surface, SPRITE_WALL, x, y);
  else if (c == 's')
    draw_image(surface, SPRITE_LADDER, x, y);
  else if (c == 'm')
    draw_image(surface, SPRITE_VILAIN_LEFT, x, y);
  else if (c == 'o')
    draw_image(surface, SPRITE_OPEN_DOOR, x, y);
  else if (c == 'i')
    {
      draw_image(surface, SPRITE_CLOSE_DOOR, x, y);
      draw_image(surface, SPRITE_PLAYER_LEFT, x, y);
    }
}

void		draw_map(t_map *map, SDL_Surface *surface)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (i < map->height)
    {
      while (j < map->width)
	{
	  char_to_sprite(map->map[i][j], BLOCK_SIZE * j, BLOCK_SIZE * i, surface);
	  ++j;
	}
      j = 0;
      ++i;
    }
}
