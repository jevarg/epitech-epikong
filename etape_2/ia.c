/*
** ia.c for rush in /home/delafo_b/tek2/rush/T2Rush1/etape_2
**
** Made by Brieuc de La Fouchardiere
** Login   <delafo_b@epitech.net>
**
** Started on  Sat Mar  8 14:57:49 2014 Brieuc de La Fouchardiere
** Last update Sat Mar  8 16:06:35 2014 Brieuc de La Fouchardiere
*/

#include "epikong.h"

void		ia_directions(t_node *node, t_character **character)
{
  int		i;

  while (i < node->nb_vilain)
    {
      if (character[i]->direction == LEFT)
	{
	  if (move_left(node, character[i]) == 0)
	    character[i]->direction = RIGHT;
	}
      else if (character[i]->direction == RIGHT)
	{
	  if (move_right(node, character[i]) == 0)
	    character[i]->direction = LEFT;
	}
      i++;
    }
}
