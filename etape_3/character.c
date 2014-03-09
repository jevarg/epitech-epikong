/*
** character.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 12:17:26 2014 Jean Gravier
** Last update Sun Mar  9 01:04:00 2014 Fritsch harold
*/

#include "epikong.h"

size_t		*get_position(t_map *map, char type)
{
  size_t	*pos;

  if ((pos = malloc(sizeof(size_t) * 2)) == NULL)
    exit_error("malloc error");
  pos[0] = 0;
  pos[1] = 0;
  while (map->map[pos[1]])
    {
      while (map->map[pos[1]][pos[0]])
	{
	  if (map->map[pos[1]][pos[0]] == type)
	    return (pos);
	  ++pos[0];
	}
      pos[0] = 0;
      ++pos[1];
    }
  return (pos);
}

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
		character->type = VILAIN;
	    }
	  ++j;
	}
      j = 0;
      ++i;
    }
}

size_t		*set_nposition(t_map *map, t_character *character,
			     char char_type, size_t *pos)
{
  size_t	i;
  size_t	j;

  i = pos[0];
  j = pos[1];
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
		character->type = VILAIN;
	      pos[0] = i;
	      pos[1] = j + 1;
	      return (pos);
	    }
	  ++j;
	}
      j = 0;
      ++i;
    }
  return (pos);
}
