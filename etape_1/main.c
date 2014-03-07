/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 21:22:45 2014 Jean Gravier
** Last update Fri Mar  7 23:19:06 2014 Fritsch harold
*/

#include <stdio.h>
#include <stdlib.h>
#include "epikong.h"

int		main(int argc, char *argv[])
{
  t_map		map;

  if (argc == 2)
    {
      feed_map(&map, argv[1]);
      //      drawmap();
    }
  return (0);
}
