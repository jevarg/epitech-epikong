/*
** intro.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 21:13:02 2014 Jean Gravier
** Last update Sat Mar  8 21:22:11 2014 Jean Gravier
*/

#include "epikong.h"

void		intro(t_node *node)
{
  size_t	*pos;

  pos = get_position(node->map, 'i');
  draw_image(node->surface, SPRITE_CLOSE_DOOR, pos[0], pos[1]);
}
