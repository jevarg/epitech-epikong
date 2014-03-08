/*
** map.c for  in /home/fritsc_h/projets/T2Rush1/etape_1
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Fri Mar  7 22:15:22 2014 Fritsch harold
** Last update Sat Mar  8 01:18:37 2014 Fritsch harold
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "epikong.h"

void		check_map(t_map *s)
{
  size_t	i;

  i = 0;
  s->width = strlen(s->map[0]);
  while (s->map && s->map[i])
    {
      if ((s->map[i][0] != 'w') || (s->map[i][strlen(s->map[i]) - 1] != 'w'))
	{
	  puts("batard");
	  exit_error(INVALID_MAP_MSG);
	}
      else if (strlen(s->map[i]) != s->width)
	{
	  printf("s->width : %d\ts->map[%lu] : %s\n", (int)s->width, i, s->map[i]);
	  puts("de tes morts");
	  exit_error(INVALID_MAP_MSG);
	}
      ++i;
    }
}

void		correct_line(char *line)
{
  if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';
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
    {
      correct_line(line);
      s->map[count_line++] = strdup(line);
    }
  s->map[count_line] = NULL;
  check_map(s);
  free(line);
}
