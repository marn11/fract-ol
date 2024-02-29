NAME = fractol

CC = cc

CFLAGS = 

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = src/main.c \
			utils/utils1.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

clean: 
	  $(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY:  clean fclean re all