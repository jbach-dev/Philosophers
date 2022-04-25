# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbach <jbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:09:26 by jbach             #+#    #+#              #
#    Updated: 2022/04/22 11:21:47 by jbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

SRCS = main.c\
ft_error.c\
ft_close.c\
ft_verif_argu.c\
utils/ft_utils.c\
utils/ft_utils_sup.c\
utils/ft_atol.c\
utils/ft_atoi.c\
ft_init_table.c\
ft_init_philo.c\
actions/ft_routine.c\
actions/ft_eat.c\
actions/ft_die.c\
actions/ft_sleep.c


OBJETS = ${SRCS:.c=.o}
LFLAG = -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJETS) 
	$(CC) $(LFLAG) $(OBJETS) -o $@

clean:
	$(RM) $(OBJETS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
