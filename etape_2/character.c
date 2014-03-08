/*
** character.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 12:17:26 2014 Jean Gravier
** Last update Sat Mar  8 13:12:40 2014 Jean Gravier
*/

#include "epikong.h"

void		set_position(t_map *map, t_character *character, char char_type)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  if (char_type != 'i' && char_type != 'm')
    exit_error("Invalid type in set_position.");
  while (i < map->height)
    {
      while (j < map->width)
	{
	  if (map->map[i][j] == char_type)
	    {
	      character->x = j;
	      character->y = i;
	      if (char_type == 'i')
		character->type = PLAYER;
	      else if (char_type == 'm')
		character->type = MONSTER;
	    }
	  ++j;
	}
      j = 0;
      ++i;
    }
}
