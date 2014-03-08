/*
** epikong.h for  in /home/fritsc_h/projets/T2Rush1/etape_1
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Mar  7 21:39:40 2014 Fritsch harold
<<<<<<< HEAD
** Last update Sat Mar  8 12:24:10 2014 Jean Gravier
=======
** Last update Sat Mar  8 12:20:53 2014 Brieuc de La Fouchardiere
>>>>>>> 299a96adaaf3640d938948200c6772e7f894fabe
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_
# define BLOCK_SIZE 30

# define INVALID_MAP_MSG "Invalid map"
# define SPRITE_WALL "../data/map/wall3.png"
# define SPRITE_LADDER "../data/map/ladder.png"
# define SPRITE_MONSTER "../data/characters/mechant1-left.png"
# define SPRITE_OPEN_DOOR "../data/map/door-out.png"
# define SPRITE_CLOSE_DOOR "../data/map/door-enter.png"
# define SPRITE_PLAYER "../data/characters/perso1-left.png"

# include <SDL/SDL.h>

enum direction_t
  {
    LEFT,
    RIGHT
  };

enum character_t
  {
    PLAYER,
    MONSTER
  };

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		**map;
}		t_map;

typedef struct s_character
{
  character_t	type;
  int		x;
  int		y;
  direction_t	direction;
}

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

/*
** draw_map.c
*/

void		draw_map(t_map *, SDL_Surface *);

/*
** character.c
*/

void		set_position(t_map *map, t_character *character, char char_type)

/*
** vilain.c
*/

void		checkIaMovement(t_map *, t_character *, SDL_Surface *);

#endif /* !EPIKONG_H_ */
