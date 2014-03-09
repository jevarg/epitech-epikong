/*
** block.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Mar  9 22:36:37 2014 Fritsch harold
** Last update Sun Mar  9 22:36:38 2014 Fritsch harold
*/

#include "epikong.h"

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
  if (node->player->key
      && node->map->map[node->player->y][node->player->x] == 'o')
    player_win(node);
  draw_stuff(node);
}
