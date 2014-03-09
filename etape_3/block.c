/*
** block.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 20:12:34 2014 Jean Gravier
** Last update Sun Mar  9 22:31:54 2014 Fritsch harold
*/

#include "epikong.h"

void		on_character()
{

}

void		check_current_block(t_node *node)
{
  size_t	i;

  i = 0;
  while (i < node->nb_vilains)
    {
      if (node->player->x == node->vilains[i]->x &&
	  node->player->y == node->vilains[i]->y)
	{
	  node->player->life -= 1;
	  if (node->player->life <= 0)
	    player_die(node);
	}
      ++i;
    }
  draw_stuff(node);
}
