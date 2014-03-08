/*
** draw_map.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 20:58:06 2014 Jean Gravier
** Last update Sat Mar  8 00:59:25 2014 Jean Gravier
*/

#include <stdlib.h>
#include <stdio.h>
#include "epikong.h"

void		draw_map(SDL_Surface *surface)
{
  int		i;

  draw_image(surface, "../data/map/door-enter.png", BLOCK_SIZE * 0, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/door-out.png", BLOCK_SIZE * 1, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/ladder.png", BLOCK_SIZE * 2, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall1.png", BLOCK_SIZE * 3, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall2.png", BLOCK_SIZE * 4, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall3.png", BLOCK_SIZE * 5, BLOCK_SIZE * 0);

  draw_image(surface, "../data/characters/mechant1-right.png", BLOCK_SIZE * 0, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/mechant2-left.png", BLOCK_SIZE * 1, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/mechant3-right.png", BLOCK_SIZE * 2, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso1-left.png", BLOCK_SIZE * 3, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso2-right.png", BLOCK_SIZE * 4, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso3-left.png", BLOCK_SIZE * 5, BLOCK_SIZE * 1);
}
