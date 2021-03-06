# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 11:49:28 by bmoran-f          #+#    #+#              #
#    Updated: 2019/11/19 11:49:32 by bmoran-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME=get_next_line.a

CC=gcc

CFLAGS=  -Werror -Wextra -D BUFFER_SIZE=999

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRC=get_next_line.c get_next_line_utils.c

SRCBONUS=get_next_line_bonus.c get_next_line_utils_bonus.c

OBJBONUS=$(SRCBONUS:.c=.o)

OBJ=$(SRC:.c=.o)

$(NAME): ./get_next_line.h
	@$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "| get_next_line.a |"
	@echo "|   was created   |"
	@echo "[=================]"


bonus:./get_next_line_bonus.h
	@$(CC) $(CFLAGS) -c $(SRCBONUS) $(HDDIRS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)

all: clean fclean $(NAME)

clean:
	@$(RM) $(OBJ) 
	@$(RM) $(OBJBONUS)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(OBJBONUS)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "| get_next_line.a |"
	@echo "|   was removed   |"
	@echo "[=================]"

re: fclean all

.PHONY: clean fclean all
