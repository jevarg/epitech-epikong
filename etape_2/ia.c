/*
** ia.c for rush in /home/delafo_b/tek2/rush/T2Rush1/etape_2
**
** Made by Brieuc de La Fouchardiere
** Login   <delafo_b@epitech.net>
**
** Started on  Sat Mar  8 14:57:49 2014 Brieuc de La Fouchardiere
** Last update Sat Mar  8 17:44:04 2014 Jean Gravier
*/

#include "epikong.h"

void		move_ia(t_node *node, t_character **character)
{
  size_t	i;

  i = 0;
  while (i < node->nb_vilains)
    {
      if (character[0][i].direction == LEFT)
	{
	  if (move_left(node, &character[0][i]) == 0)
	    character[0][i].direction = RIGHT;
	}
      else if (character[0][i].direction == RIGHT)
	{
	  if (move_right(node, &character[0][i]) == 0)
	    character[0][i].direction = LEFT;
	}
      ++i;
    }
}
