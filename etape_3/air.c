/*
** air.c for  in /home/fritsc_h/projets/T2Rush1/etape_2
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Mar  9 01:55:49 2014 Fritsch harold
** Last update Sun Mar  9 20:03:59 2014 Fritsch harold
*/

#include <unistd.h>
#include "epikong.h"

void		jump_left(t_node *node)
{
  if ((node->map->map[node->player->y + 1][node->player->x] == 'w')
      || (node->map->map[node->player->y + 1][node->player->x] == 's'))
    if (move_up(node, node->player))
      {
	node->player->in_air = TRUE;
	usleep(10000);
	if (move_left(node, node->player))
	  {
	    usleep(10000);
	    if (move_left(node, node->player))
	      {
		usleep(10000);
		move_left(node, node->player);
	      }
	  }
      }
  fall(node);
  node->player->in_air = FALSE;
}

void		jump_right(t_node *node)
{
  if ((node->map->map[node->player->y + 1][node->player->x] == 'w')
      || (node->map->map[node->player->y + 1][node->player->x] == 's'))
    if (move_up(node, node->player))
      {
	node->player->in_air = TRUE;
	usleep(10000);
	if (move_right(node, node->player))
	{
	  usleep(10000);
	  if (move_right(node, node->player))
	    {
	      usleep(10000);
	      move_right(node, node->player);
	    }
	}
    }
  fall(node);
  node->player->in_air = FALSE;
}

char		first_cell_fall(t_node *node)
{
  usleep(FALL_SPEED);
  if (landing(node) == 0)
    return (1);
  move_ia(node);
  usleep(FALL_SPEED / 2);
  if (landing(node) == 0)
    return (1);
  return (0);
}

void		fall(t_node *node)
{
  size_t	i;
  size_t	speed;
  size_t	count;

  i = 1;
  count = 2;
  while (!is_walkable(node->map, node->player->x, node->player->y + 1))
    {
      if (i == 1)
	{
	  if (first_cell_fall(node))
	    return ;
	  i = 2;
	}
      speed = 0;
      while (speed < (i * i))
	{
	  usleep(FALL_SPEED / (i * i));
	  check_fall_dead(node, count);
	  if (landing(node) == 0)
	    return ;
	  ++speed;
	  ++count;
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
