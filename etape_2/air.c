/*
** air.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 01:32:32 2014 Jean Gravier
** Last update Sun Mar  9 01:32:32 2014 Jean Gravier
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
  if (!move_down(node, node->player))
    return (1);
  move_ia(node);
  usleep(FALL_SPEED / 2);
  if (!move_down(node, node->player))
    return (1);
  return (0);
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
	  if (first_cell_fall(node))
	    return ;
	  i = 2;
	  move_ia(node);
	}
      speed = 0;
      while (speed < (i * i))
	{
	  usleep(FALL_SPEED / (i * i));
	  if (!move_down(node, node->player))
	    return ;
	  ++speed;
	}
      ++i;
      move_ia(node);
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
	  move_ia(node);
	}
      fall(node);
    }
}
