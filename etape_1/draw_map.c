/*
** draw_map.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 20:58:06 2014 Jean Gravier
** Last update Sat Mar  8 01:20:28 2014 Jean Gravier
*/

#include <stdlib.h>
#include <stdio.h>
#include "epikong.h"

char		*char_to_sprite(char c)
{
  if (c == 'w')
    return (SPRITE_WALL);
  else if (c == 's')
    return (SPRITE_LADDER);
  else if (c == 'm')
    return (SPRITE_MONSTER);
  else if (c == 'o')
    return (SPRITE_OPEN_CLOSE);
  else if (c == 'i')
    return (SPRITE_CLOSE_DOOR);
}

void		draw_map(t_map *map, SDL_Surface *surface)
{
  int		i;
  int		j;

  while (i < map->height)
    {
      while (j < map->width)
	{
	  draw_image(surface, char_to_sprite(map[i][j]),
		     BLOCK_SIZE * i, BLOCK_SIZE * j);
	}
    }
}
