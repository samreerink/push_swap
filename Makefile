# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: sreerink <sreerink@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2024/01/12 14:43:57 by sreerink      #+#    #+#                  #
#    Updated: 2024/02/15 15:59:29 by sreerink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 		push_swap

RM= 		rm -rf

FLAGS= 		-Wall -Werror -Wextra

SRC_DIR=	src

OBJ_DIR=	obj

SRCS= 		$(addprefix $(SRC_DIR)/, main.c operations.c moves_push.c \
		moves_swap.c moves_rotate.c moves_rev_rotate.c radix_sort.c \
		small_sort.c small_sort_utils.c atoi_overflow.c checks.c \
		parsing.c sorting.c stack_init.c stack_utils.c)

OBJ=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFT=		./Libft/libft.a

HEADERS=	-I ./Libft -I ./include


all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./Libft

$(NAME): 	$(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L./Libft -lft -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	$(MAKE) -C ./Libft clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./Libft fclean

re:		fclean all

.PHONY:	all clean fclean re
