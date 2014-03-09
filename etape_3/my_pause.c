/*
** my_pause.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 23:39:49 2014 Jean Gravier
** Last update Sun Mar  9 23:41:55 2014 Jean Gravier
*/

#include "epikong.h"

void		my_pause()
{
  int		stop;
  SDL_Event	event;

    stop = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_KEYDOWN)
	stop = 1;
    }
}
