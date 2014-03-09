/*
** map.c for  in /home/fritsc_h/projets/T2Rush1/etape_1
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Mar  7 22:15:22 2014 Fritsch harold
** Last update Sun Mar  9 23:09:25 2014 Jean Gravier
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "epikong.h"

int		set_map(t_map *map, int *select)
{
  char		*maps[5];

  maps[0] = "../data/contents/map/map1.map";
  maps[1] = "../data/contents/map/map2.map";
  maps[2] = "../data/contents/map/map3.map";
  maps[3] = "../data/contents/map/map3.map";
  maps[4] = "../data/contents/map/map4.map";
  map->path = maps[*select];
  return (0);
}

size_t		get_block_nb(t_map *map, char block_type)
{
  size_t	i;
  size_t	j;
  size_t	nb;

  i = 0;
  j = 0;
  nb = 0;
  while (i < map->height)
    {
      while (j < map->width)
	{
	  if (map->map[i][j] == block_type)
	    ++nb;
	  ++j;
	}
      j = 0;
      ++i;
    }
  return (nb);
}

void		check_map(t_map *s)
{
  size_t	i;

  i = 0;
  s->width = strlen(s->map[0]);
  while (s->map && s->map[i])
    {
      if (((s->map[i][0] != 'w') || (s->map[i][strlen(s->map[i]) - 1] != 'w'))
	  || ((strlen(s->map[i]) != s->width)))
	exit_error(INVALID_MAP_MSG);
      ++i;
    }
}

char		*correct_line(char *line)
{
  if (line)
    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = '\0';
  return (line);
}

void		feed_map(t_map *s, char *filename)
{
  FILE		*fp;
  char		*line;
  size_t	len;
  ssize_t	read;
  size_t	count_line;

  len = 0;
  count_line = 0;
  line = NULL;
  if ((fp = fopen(filename, "r")) == NULL)
    exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, fp)) != -1)
    ++count_line;
  rewind(fp);
  if ((s->map = malloc(sizeof(char *) * (count_line + 1))) == NULL)
    exit(EXIT_FAILURE);
  s->height = count_line;
  count_line = 0;
  while ((read = getline(&line, &len, fp)) != -1)
    s->map[count_line++] = strdup(correct_line(line));
  s->map[count_line] = NULL;
  check_map(s);
  free(line);
}
