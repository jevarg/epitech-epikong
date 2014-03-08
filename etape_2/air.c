/*
** air.c for  in /home/fritsc_h/projets/T2Rush1/etape_2
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sat Mar  8 18:36:57 2014 Fritsch harold
** Last update Sat Mar  8 20:40:04 2014 Fritsch harold
*/

#include <unistd.h>
#include "epikong.h"

void		jump_left(t_node *node)
{
  if ((node->map->map[node->player->y + 1][node->player->x] == 'w')
      || (node->map->map[node->player->y + 1][node->player->x] == 's'))
    if (move_up(node, node->player))
      {
	usleep(10000);
	if (move_left(node, node->player))
	  {
	    usleep(10000);
	    move_left(node, node->player);
	  }
      }
  fall(node);
}

void		jump_right(t_node *node)
{
  if ((node->map->map[node->player->y + 1][node->player->x] == 'w')
      || (node->map->map[node->player->y + 1][node->player->x] == 's'))
    if (move_up(node, node->player))
      {
	usleep(10000);
	if (move_right(node, node->player))
	{
	  usleep(10000);
	  move_right(node, node->player);
	}
    }
  fall(node);
}

void		fall(t_node *node)
{
  size_t	i;
  size_t	speed;
  
  i = 1;
  while (!is_walkable(node->map, node->player->x, node->player->y + 1))
    {
      if (i == 1)
	{
	  usleep(FALL_SPEED);
	  move_down(node, node->player);
	  usleep(FALL_SPEED / 2);
	  move_down(node, node->player);
	  i = 2;
	}
      speed = 0;
      while (speed < (i * i))
	{
	  usleep(FALL_SPEED / (i * i));
	  move_down(node, node->player);
	  ++speed;
	}
      ++i;
    }
}

void		jump(t_node *node)
{
  if (!is_walkable(node->map, node->player->x, node->player->y - 1))
    {
      move_up(node, node->player);
      usleep(FALL_SPEED);
      if (!is_walkable(node->map, node->player->x, node->player->y - 1))
	{
	  move_up(node, node->player);
	  usleep(FALL_SPEED);
	}
      fall(node);
    }
}
