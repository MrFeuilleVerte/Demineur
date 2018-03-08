##
## Makefile for makefile in /home/vincent/Delivery/Rush_Scroller/Program
##
## Made by Vincent
## Login   <vincent.vaucouleur@epitech.eu>
##
## Started on  Sat Apr  1 15:13:05 2017 Vincent
## Last update Sun May 28 23:50:56 2017 Vincent
##

CC      =       gcc

RM      =       rm -f

SRCS	=	$(wildcard src/*.c)	\
		$(wildcard basics/*.c)

OBJ     =       $(SRCS:.c=.o)

NAME    =       demineur

CFLAGS  =	-I./include
CFLAGS	+=	-g3

LDFLAGS	=	-lc_graph_prog_full -lm

all:    $(NAME)

$(NAME):        $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:    %.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "COMPILE -" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
