# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:04:39 by tcherepoff        #+#    #+#              #
#    Updated: 2025/03/29 21:07:09 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_EXE		=	srcs/execution/checker.c		\
					srcs/execution/main.c			\
					srcs/execution/mutex.c			\
					srcs/execution/pair.c			\
					srcs/execution/side_functions.c	\
					srcs/execution/executate.c		\
					srcs/execution/init.c			\

SRCS_PARSING	=	srcs/parsing/parsing.c		\
					srcs/parsing/utils_error.c	\
					srcs/parsing/utils_libft.c	\

SRCS = $(SRCS_PARSING) $(SRCS_EXE)

OBJS = $(SRCS:.c=.o)

CC = cc
FLAG = -Wall -Werror -Wextra -Iincludes -fsanitize=address -g3
RM = @rm -f
AR = ar rcs

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) -o $(NAME)
			@echo Done!

all:		$(NAME)

clean:
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean