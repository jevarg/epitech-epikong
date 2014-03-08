/*
** movement.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 12:26:37 2014 Jean Gravier
** Last update Sat Mar  8 13:29:10 2014 Jean Gravier
*/

#include "epikong.h"

int		valid(t_map *map, size_t x, size_t y)
{
  if ((x >= map->width && y >= map->height)
      && (x < 0 && y < 0))
    return (0);
  if (map->map[y][x] != 'w')
    return (1);
  return (0);
}

void		move_left(t_node *node)
{
  if ((node->character->x - 1) > 0
      && valid(node->map, node->character->x - 1, node->character->y))
    {
      node->character->x -= 1;
      draw_image(node->surface, SPRITE_PLAYER_LEFT, node->character->x * BLOCK_SIZE, node->character->y * BLOCK_SIZE);
    }

}

void		move_right(t_node *node)
{
  if ((node->character->x + 1) < node->map->width
      && valid(node->map, node->character->x + 1, node->character->y))
    {
      node->character->x += 1;
      draw_image(node->surface, SPRITE_PLAYER_RIGHT, node->character->x * BLOCK_SIZE, node->character->y * BLOCK_SIZE);
    }

}
