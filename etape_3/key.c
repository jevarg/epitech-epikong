/*
** key.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Mar  9 21:19:18 2014 Fritsch harold
** Last update Sun Mar  9 22:04:16 2014 Fritsch harold
*/

#include "epikong.h"

void		get_key(t_node *node)
{
  if (node->map->map[node->player->y][node->player->x] == 'k')
    {
      node->player->key = TRUE;
      node->map->map[node->player->y][node->player->x] = '.';
    }
}
