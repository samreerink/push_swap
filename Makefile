# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: sreerink <sreerink@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2024/01/12 14:43:57 by sreerink      #+#    #+#                  #
#    Updated: 2024/02/17 01:56:39 by sreerink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 		push_swap

BONUS_NAME=	checker

RM= 		rm -rf

FLAGS= 		-Wall -Werror -Wextra

SRC_DIR=	src

OBJ_DIR=	obj

B_SRC_DIR=	bonus/src

B_OBJ_DIR=	bonus/obj

SRCS= 		$(addprefix $(SRC_DIR)/, main.c operations.c moves_push.c \
		moves_swap.c moves_rotate.c moves_rev_rotate.c radix_sort.c \
		small_sort.c small_sort_utils.c atoi_overflow.c checks.c \
		parsing.c sorting.c stack_init.c stack_utils.c stack_free.c)

OBJ=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

BONUS_SRCS=	$(addprefix $(B_SRC_DIR)/, main.c checker.c)

BONUS_OBJ=	$(patsubst $(B_SRC_DIR)/%.c, $(B_OBJ_DIR)/%.o, $(BONUS_SRCS))

LIBFT=		./Libft/libft.a

HEADERS=	-I ./Libft -I ./include

B_HEADERS=	-I ./Libft -I ./include -I ./bonus/include

all:		$(NAME)

bonus:		$(BONUS_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(B_HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./Libft

$(NAME): 	$(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L./Libft -lft -o $(NAME)

$(BONUS_NAME):	$(LIBFT) $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -L./Libft -lft -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)
	$(RM) $(OBJ_DIR)
	$(RM) $(B_OBJ_DIR)
	$(MAKE) -C ./Libft clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(MAKE) -C ./Libft fclean

re:		fclean all

.PHONY:	all clean fclean re bonus
