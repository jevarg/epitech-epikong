/*
** menu_maps.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 22:55:05 2014 Jean Gravier
** Last update Sun Mar  9 23:04:22 2014 Jean Gravier
*/

#include "epikong.h"

char	*get_maps(int i)
{
  char	*maps[5];

  maps[0] = "../data/contents/menu/thumb/map1.png";
  maps[1] = "../data/contents/menu/thumb/map2.png";
  maps[2] = "../data/contents/menu/thumb/map3.png";
  maps[3] = "../data/contents/menu/thumb/map4.png";
  maps[4] = "../data/contents/menu/thumb/map5.png";
  return (maps[i]);
}
