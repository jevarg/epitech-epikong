/*
** dead.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sun Mar  9 14:42:51 2014 Fritsch harold
** Last update Sun Mar  9 19:53:43 2014 Fritsch harold
*/

#include "epikong.h"

void	dead(t_node *node)
{
  puts("mort");
  node->player->live = 0;
}

void	check_fall_dead(t_node *node, int fall_height)
{
  if (fall_height >= 4)
    dead(node);
}
