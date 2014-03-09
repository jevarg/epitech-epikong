/*
** epikong.h for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 20:52:57 2014 Jean Gravier
** Last update Sun Mar  9 01:24:15 2014 Fritsch harold
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_
# define BLOCK_SIZE 30
# define FALL_SPEED 50000
# define TRUE 1
# define FALSE 0

# define INVALID_MAP_MSG "Invalid map"
# define SPRITE_WALL "../data/contents/world/wall4.png"
# define SPRITE_LADDER "../data/contents/world/ladder.png"
# define SPRITE_VILAIN_LEFT "../data/characters/vilain1/mechant1-left.png"
# define SPRITE_VILAIN_RIGHT "../data/characters/vilain1/mechant1-right.png"
# define SPRITE_OPEN_DOOR "../data/contents/world/car-out.png"
# define SPRITE_CLOSE_DOOR "../data/contents/world/in-helicrash.png"
# define SPRITE_PLAYER_LEFT "../data/characters/perso3/perso3-left.png"
# define SPRITE_PLAYER_RIGHT "../data/characters/perso3/perso3-right.png"

# include <SDL/SDL.h>

typedef enum e_direction
  {
    LEFT,
    RIGHT
  }t_direction;

typedef enum e_type
  {
    PLAYER,
    VILAIN
  }t_type;

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		**map;
}		t_map;

typedef struct	s_character
{
  t_type	type;
  size_t	x;
  size_t	y;
  t_direction	direction;
  char		in_air;
}		t_character;

typedef struct	s_node
{
  t_map		*map;
  t_character	*player;
  t_character	**vilains;
  size_t	nb_vilains;
  SDL_Surface	*surface;
}		t_node;

/*
** map.c
*/

void		check_map(t_map *);
void		feed_map(t_map *, char *);
char		*correct_line(char *);
size_t		get_block_nb(t_map *, char);

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

/*
** character.c
*/

void		set_position(t_map *, t_character *, char);
size_t		*set_nposition(t_map *, t_character *, char, size_t[2]);
void		set_char_type(t_character *, char, int, int);

/*
** ia.c
*/

void		move_ia(t_node *);

/*
** check.c
*/

int		valid(t_map *, size_t, size_t);
int		is_walkable(t_map *, size_t, size_t);
SDL_Surface	*get_old_block(t_node *, size_t, size_t, t_character *);
void		check_keys(t_node *, Uint8 *, int *);

/*
** movement.c
*/

void		fill_rect(t_character *, SDL_Rect *);
int		move_left(t_node *, t_character *);
int		move_right(t_node *, t_character *);
int		move_up(t_node *, t_character *);
int		move_down(t_node *, t_character *);

/*
** air.c
*/

void		jump_left(t_node *);
void		jump_right(t_node *);
void		jump(t_node *);
char		first_cell_fall(t_node *);
void		fall(t_node *);

/*
** ladder.c
*/

int		ladder_up(t_node *);
void		ladder_down(t_node *);

#endif /* !EPIKONG_H_ */
