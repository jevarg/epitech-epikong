##
## Makefile for  in /home/fritsc_h/projets/T2Rush1/etape_3
## 
## Made by Fritsch harold
## Login   <fritsc_h@epitech.net>
## 
## Started on  Sun Mar  9 22:27:21 2014 Fritsch harold
## Last update Sun Mar  9 22:27:22 2014 Fritsch harold
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
