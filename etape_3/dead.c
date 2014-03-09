/*
** dead.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Sun Mar  9 14:42:51 2014 Fritsch harold
** Last update Sun Mar  9 22:29:43 2014 Jean Gravier
*/

#include "epikong.h"

void		player_die(t_node *node)
{
  int		x;
  int		y;

  x = ((node->surface->w / 2) - (474 / 2));
  y = ((node->surface->h / 2) - (392 / 2));
  SDL_FillRect(node->surface, NULL, SDL_MapRGB(node->surface->format, 0, 0, 0));
  draw_image(node->surface, SPRITE_GAMEOVER, x, y);
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
