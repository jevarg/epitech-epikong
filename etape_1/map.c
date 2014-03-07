/*
** map.c for  in /home/fritsc_h/projets/T2Rush1/etape_1
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Fri Mar  7 22:15:22 2014 Fritsch harold
** Last update Sat Mar  8 00:50:59 2014 Fritsch harold
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "epikong.h"



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
      if ((line[0] != 'w') || (line[strlen(line) - 2] != 'w'))
	{
	  fprintf(stderr, "map incorrecte\n");
	  exit(EXIT_FAILURE);
	}
      line[strlen(line) - 1] = '\0';
      s->map[count_line++] = strdup(line);
    }
  s->width = strlen(s->map[0]);
  s->map[count_line] = NULL;
  free(line);
}
