/*
** win.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 21:58:07 2014 Jean Gravier
** Last update Sun Mar  9 22:28:14 2014 Jean Gravier
*/

#include "epikong.h"

void		player_win(t_node *node)
{
  int		x;
  int		y;

  x = ((node->surface->w / 2) - (474 / 2));
  y = ((node->surface->h / 2) - (392 / 2));
  SDL_FillRect(node->surface, NULL, SDL_MapRGB(node->surface->format, 0, 0, 0));
  draw_image(node->surface, SPRITE_WIN, x, y);
  node->stop = 3;
}
