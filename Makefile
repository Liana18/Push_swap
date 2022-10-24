NAME		= push_swap
SRC			= $(wildcard src/*/*.c)
SRC			+= $(wildcard src/*.c)
OBJS		= $(SRC:.c=.o)
INCLUDES	= ./includes 
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
CC			= cc

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)  
			rm -rf ~/LIbrary/Caches

re		:fclean all
.PHONY: all clean fclean re
