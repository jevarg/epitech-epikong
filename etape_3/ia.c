/*
** ia.c for rush in /home/delafo_b/tek2/rush/T2Rush1/etape_2
**
** Made by Brieuc de La Fouchardiere
** Login   <delafo_b@epitech.net>
**
** Started on  Sat Mar  8 14:57:49 2014 Brieuc de La Fouchardiere
** Last update Sun Mar  9 23:01:28 2014 Fritsch harold
*/

#include <unistd.h>
#include "epikong.h"

void		ia_cycle(t_node* node, int *i)
{
  *i = -1;
  while (*i < 4 && !node->stop)
    {
      *i += 1;
      move_ia(node);
    }
}

void		move_ia(t_node *node)
{
  size_t	i;

  i = 0;
  while (i < node->nb_vilains && !node->stop)
    {
      if (node->vilains[i]->direction == LEFT)
	{
	  if (move_left(node, node->vilains[i]) == 0)
	    node->vilains[i]->direction = RIGHT;
	}
      else if (node->vilains[i]->direction == RIGHT)
	{
	  if (move_right(node, node->vilains[i]) == 0)
	    node->vilains[i]->direction = LEFT;
	}
      check_current_block(node);
      ++i;
    }
  SDL_Flip(node->surface);
}
