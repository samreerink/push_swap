# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: sreerink <sreerink@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2024/01/12 14:43:57 by sreerink      #+#    #+#                  #
#    Updated: 2024/01/12 14:44:33 by sreerink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 		push_swap

RM= 		rm -rf

FLAGS= 		-Wall -Werror -Wextra

SRCS= 		main.c

OBJ= 	$(SRCS:.c=.o)

LIBFT=		./Libft/libft.a

all:		$(NAME)

%.o:		%.c
	$(CC) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./Libft

$(NAME): 	$(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L./Libft -lft -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./Libft clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./Libft fclean

re:		fclean $(NAME)

.PHONY:	all clean fclean re
