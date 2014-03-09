/*
** menu.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 21:45:53 2014 Jean Gravier
** Last update Sun Mar  9 01:38:55 2014 Jean Gravier
*/

#include <unistd.h>
#include "epikong.h"

char		*pause_menu(t_map *map)
{
  int		stop;
  SDL_Event	event;

  stop = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      usleep(50000);
      if (event.type == SDL_QUIT)
	stop = 1;
      /*      else if (event.type == SDL_MOUSEBUTTONUP)
	{
	  if (event.button.button == SDL_BUTTON_LEFT)
	    check_click(map);
	}
      else if (event.type == SDL_MOUSEMOTION)
	if ()*/
    }
}

void		menu(SDL_Surface *surface, t_map *map)
{
  SDL_Rect	rect;
  SDL_Surface	*background;

  rect.x = 0;
  rect.y = 0;
  rect.w = 800;
  rect.h = 600;
  surface = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  //SDL_FillRect(background, NULL, SDL_MapRGB(surface->format, 82, 82, 82));
  draw_image(surface, "../data/map/backgrounds/bg.png", 0, 0);
  draw_image(surface, "../data/foto.png", ((800 / 2) - (426 / 2)), 100);
  SDL_Flip(surface);
  pause_menu(map);
  SDL_FreeSurface(surface);
  //  SDL_Quit();
  //exit(1);
}
