# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 18:30:32 by kahmada           #+#    #+#              #
#    Updated: 2024/04/26 13:16:39 by kahmada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = push_swap
BONUS_NAME = checker
CC         = cc
CFLAGS     = -Wall -Werror -Wextra
RM         = rm -f

SRC = Mandatory/libftfunc.c \
      Mandatory/ft_atoi.c \
      Mandatory/ft_split.c \
      Mandatory/parcing.c \
      Mandatory/free_errors.c \
      Mandatory/push_swap.c \
      Mandatory/fonction_utilise.c \
      Mandatory/initialise_stack.c \
      Mandatory/operation_my_a.c \
      Mandatory/operation_my_b.c \
      Mandatory/sort_3_4_5.c \
      Mandatory/sort_stacks.c

SRC_BONUS = Bonus/checker.c \
            Bonus/fonction_utilise.c \
            Bonus/free_errors.c \
            Bonus/ft_split.c \
            Bonus/ft_atoi.c\
            Bonus/get_next_line.c \
            Bonus/get_next_line_utils.c \
            Bonus/initialise_stack.c \
            Bonus/libftfunc.c \
            Bonus/operation_my_a.c \
            Bonus/operation_my_b.c \
            Bonus/parcing.c \
            Bonus/op.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS_NAME)

Mandatory/%.o: Mandatory/%.c Mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


Bonus/%.o: Bonus/%.c Bonus/checker.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(B_OBJ) 

fclean: clean
	rm -f $(NAME) $(B_OBJ)

re: fclean all