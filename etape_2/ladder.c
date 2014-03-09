/*
** ladder.c for  in /home/fritsc_h/projets/T2Rush1/etape_2
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sat Mar  8 20:33:07 2014 Fritsch harold
** Last update Sun Mar  9 01:54:22 2014 Fritsch harold
*/

#include "epikong.h"

int	ladder_up(t_node *node)
{
  if (node->map->map[node->player->y][node->player->x] == 's')
    {
      move_up(node, node->player);
      return (1);
    }
  return (0);
}

void	ladder_down(t_node *node)
{
  if (node->map->map[node->player->y + 1][node->player->x] == 's')
    move_down(node, node->player);
}

char		landing(t_node *node)
{
  char		c;

  c = node->map->map[node->player->y + 1][node->player->x];
  if ((c != 'w') && (c != 's'))
    {
      move_down(node, node->player);
      return (1);
    }
  return (0);
}
