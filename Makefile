NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS =	src/main.c \
		src/init.c \
		src/rendering.c \
		src/scaling.c \
		src/events.c \
		src/maths.c \
		utils/utils1.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c utils/utils.h
	$(CC) -g $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) -g $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

clean:
	  $(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY:  clean fclean re all
