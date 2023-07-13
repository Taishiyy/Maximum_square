NAME = bsq

SRCS = main.c \
	   solve.c \
	   start.c \
	   get_filesize.c \
	   map_error_check.c \
	   start_error.c \
	   all_error.c 
	   
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re