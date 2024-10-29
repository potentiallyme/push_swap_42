# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 03:44:44 by lmoran            #+#    #+#              #
#    Updated: 2024/02/13 15:18:37 by lmoran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#...............................................#

NAME	= push_swap
CC		= @clang -g3
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear
FILE	= $(shell ls -l src/ | grep -F .c | wc -l)
HEAD	= ./include/push_swap.h
CMP		= 1

#...............................................#

SRC	= ./src/push_swap.c\
	  ./src/ft_checks.c\
	  ./src/ft_utils.c\
	  ./src/ft_utils2.c\
	  ./src/ft_sasb.c\
	  ./src/ft_papb.c\
	  ./src/ft_rarb.c\
	  ./src/ft_rrarrb.c\
	  ./src/ft_sort.c\
	  ./src/ft_cost.c\
	  ./src/ft_do_it.c\
	  ./src/ft_move.c\

OBJ	= $(SRC:.c=.o)

#...............................................#

PRINT_PATH	= ./libft --no-print-directory
PRINT_NAME	= ./libft/libft.a

#...............................................#

BONUS 	= checker

BONUS_SRC = 	./src/ft_checks.c\
				./src/ft_utils.c\
				./src/ft_utils2.c\
				./src/ft_sasb.c\
				./src/ft_papb.c\
				./src/ft_rarb.c\
				./src/ft_rrarrb.c\
				./src/ft_sort.c\
				./src/ft_cost.c\
				./src/ft_do_it.c\
				./src/ft_move.c\
				./bonus/checker.c\
				./bonus/checker_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)



#...............................................#

BOLD	= 	\e[1m
FADE	=	\e[2m
ITA		=	\e[3m
BLINK	=	\e[5m
GREEN	=	\e[38;5;76m
RED		=	\e[38;5;196m
YELLOW	=	\e[38;5;227m
ORANGE	=	\e[38;5;208m
PURPLE	=	\e[38;5;201m
LBLUE	=	\e[38;5;45m
BLUE	=	\e[38;5;27m
INDI	=	\e[38;5;91m
SPINK	=	\e[38;5;225m
GREY	=	\e[38;5;254m
PEACH	=	\e[38;5;223m
RESET	=	\e[00m

#...............................................#

RNBW	= @printf "                                                          \r$(ITA)$(RED)pu$(ORANGE)sh_$(YELLOW)swa$(GREEN)p i$(LBLUE)s re$(BLUE)ad$(INDI)y to$(PURPLE)o!$(RESET)\n\r$(GREEN). $(LBLUE). $(BLUE). $(INDI). $(PURPLE). $(RED). $(ORANGE). $(YELLOW). $(GREEN). $(LBLUE). $(BLUE). $(INDI).                       \n"
RNBW_B	= @printf "                                                          \r$(ITA)$(RED)th$(ORANGE)e ch$(YELLOW)eck$(GREEN)er i$(LBLUE)s re$(BLUE)ad$(INDI)y to$(PURPLE)o!$(RESET)\n\r$(GREEN). $(LBLUE). $(BLUE). $(INDI). $(PURPLE). $(RED). $(ORANGE). $(YELLOW). $(GREEN). $(LBLUE). $(BLUE). $(INDI). $(PURPLE).                      \n"

all: $(PRINT_NAME) $(NAME) $(BONUS)

m: $(PRINT_NAME) $(NAME)

b: $(PRINT_NAME) $(BONUS)



%.o: %.c $(HEAD)
	@printf "\r$(FAINT)$(SPINK)Compiling $(RESET)$(GREEN)$<$(BLUE) [$(SPINK)$(CMP)$(BLUE)/$(SPINK)$(FILE)$(BLUE)]$(RESET)                       \r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))
	
$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(PRINT_NAME) -o $(NAME)
	$(RNBW)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(CFLAGS) $(PRINT_NAME) -o $(BONUS)
	$(RNBW_B)

clean:
	@rm -f $(OBJ) $(PRINT_NAME) $(BONUS_OBJ)
	@printf "\r\n\r$(GREEN)ALL CLEAN!...\n\n"
	$(RM) $(OBJ)


fclean: clean
	@make fclean -C $(PRINT_PATH)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@printf "\r$(PEACH)$(FADE)...and f'd!\n\n"
	$(RM) $(NAME)

re: fclean all

reb: fclean bonus

.PHONY: 
	all clean fclean re