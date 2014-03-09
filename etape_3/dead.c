/*
** dead.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Sun Mar  9 14:42:51 2014 Fritsch harold
** Last update Sun Mar  9 20:57:45 2014 Jean Gravier
*/

#include "epikong.h"

void	player_die(t_node *node)
{
  draw_image(node->surface, SPRITE_GAMEOVER, 0, 0);
  node->stop = 2;
}

void	dead(t_node *node)
{
  node->player->life = 0;
  player_die(node);
}

void	check_fall_dead(t_node *node, int fall_height)
{
  if (fall_height >= 4)
    dead(node);
}
