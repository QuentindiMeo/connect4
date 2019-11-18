##
## PERSONAL PROJECT, 2019
## connect4
## File description:
## Makefile
##

SRC	=	src/error.c		\
		src/detectors2.c	\
		src/detectors.c		\
		src/game_loop.c		\
		src/setup2.c		\
		src/setup.c		\
		src/malloc_free.c	\
		src/main_connect4.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	connect4

.PHONY: clean fclean re connect4

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
