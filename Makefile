NAME = fractol

NAME_BONUS = fractol_bonus

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
		utils/utils2.c \

SRCS_BONUS =	bonus_src/main_bonus.c \
				bonus_src/init_bonus.c \
				bonus_src/rendering_bonus.c \
				bonus_src/scaling_bonus.c \
				bonus_src/events_bonus.c \
				bonus_src/maths_bonus.c \
				bonus_utils/utils1_bonus.c \
				bonus_utils/utils2_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

%_bonus.o : bonus_src/%.c bonus_utils/%.c bonus_src/bonus_fractol.h bonus_utils/bonus_utils.h
	$(CC) -O3 $(CFLAGS) -c $< -o $@

%.o: %.c utils/utils.h fractol.h
	$(CC) -O3 $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) -O3 $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) -O3 $(CFLAGS) $(MLX) -o $(NAME_BONUS) $(OBJS_BONUS)

$(OBJS_BONUS): bonus_src/bonus_fractol.h bonus_utils/bonus_utils.h

clean:
	  $(RM) $(OBJS) $(OBJS_BONUS)

fclean: 	clean
				$(RM) $(NAME) $(NAME_BONUS)

re: 		fclean all

.PHONY:  clean fclean re all
