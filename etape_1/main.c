/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 21:22:45 2014 Jean Gravier
** Last update Fri Mar  7 23:35:18 2014 Jean Gravier
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void		pause()
{
  int		stop;
  SDL_Event	event;

  stop = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	stop = 1;
      else if (SDL_KEYDOWN)
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  stop = 1;
    }
}

int		main(int argc, char *argv[])
{
  SDL_Surface	*surface;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur initialisation SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 73, 73, 73));
  SDL_Flip(surface);
  draw_map(surface);
  pause();
  SDL_Quit();
  return (0);
}
