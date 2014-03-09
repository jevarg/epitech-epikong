/*
** epikong.h for  in /home/fritsc_h/projets/T2Rush1/etape_1
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Mar  7 21:39:40 2014 Fritsch harold
** Last update Sun Mar  9 00:49:18 2014 Brieuc de La Fouchardiere
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_
# define BLOCK_SIZE 30

# define INVALID_MAP_MSG "Invalid map"
# define SPRITE_WALL "../data/contents/world/wall4.png"
# define SPRITE_LADDER "../data/contents/world/ladder.png"
# define SPRITE_MONSTER "../data/characters/vilain1/mechant1-left.png"
# define SPRITE_OPEN_DOOR "../data/contents/world/car-out.png"
# define SPRITE_CLOSE_DOOR "../data/contents/world/in-helicrash.png"
# define SPRITE_PLAYER "../data/characters/perso3/perso3-left.png"

# include <SDL/SDL.h>

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		**map;
}		t_map;

/*
** map.c
*/

void		check_map(t_map *);
void		feed_map(t_map *, char *);
char		*correct_line(char *);

/*
** error.c
*/

void		exit_error(char *);

/*
** draw_image.c
*/

void		draw_image(SDL_Surface *, char *, int, int);
SDL_Surface	*get_image(char *);

/*
** draw_map.c
*/

void		draw_map(t_map *, SDL_Surface *);

#endif /* !EPIKONG_H_ */
