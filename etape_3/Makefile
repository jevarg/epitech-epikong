##
## Makefile for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
##
## Made by Jean Gravier
## Login   <gravie_j@epitech.net>
##
## Started on  Fri Mar  7 21:36:25 2014 Jean Gravier
<<<<<<< HEAD
## Last update Sun Mar  9 21:33:04 2014 Fritsch harold
=======
## Last update Sun Mar  9 20:45:33 2014 Jean Gravier
>>>>>>> 0c97f300b6967fd3d77faa33ec2b566269b265a9
##

CC=		gcc

RM=		rm -f

NAME=		epikong

SRCS=		main.c \
		menu.c \
		draw_map.c \
		draw_image.c \
		draw_all_sprites.c \
		character.c \
		movement.c \
		ia.c \
		map.c \
		error.c \
		key.c \
		air.c \
		ladder.c \
		dead.c \
		check.c \
		block.c \

OBJS=		$(SRCS:.c=.o)

CFLAGS +=	-Wall -Wextra -g3

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lSDL -lSDL_image -lSDL_mixer

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
