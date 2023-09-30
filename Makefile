



.PHONY = all clean fclean re

NAME = cub3D

CC = gcc
CFLAGS = -Iminilibx-linux 
# CFLAGS += -fsanitize=address -g3 
# CFLAGS += -Wall -Werror -Wextra 

# MLX = -I /usr/local/include -L /usr/local/lib -lmlx

# FRAMEWORKS = -framework OpenGl -framework Appkit
GNL = Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c
PARS = parsing/parsing.c parsing/check_args.c parsing/check_all.c parsing/read.c parsing/check_empty.c parsing/identifiers.c parsing/colors.c parsing/map.c parsing/check_wall.c
RC = raycasting/draw_2d_map.c raycasting/mlx_utils.c raycasting/hooks_handler.c raycasting/draw_line.c raycasting/find_wall.c
SRC = cub3D.c $(RC) $(PARS) $(GNL)

OBJS = ${SRC:%.c=%.o}

all : ${NAME}

${NAME} : ${OBJS}
	cd libft && make && make bonus && cd .. 
	make -C minilibx-linux  
	$(CC) $(CFLAGS)  -o ${NAME} ${OBJS} libft/libft.a -L./minilibx-linux -lm -lmlx -lXext -lX11

clean:
	rm -rf ${OBJS}	
	make -C minilibx-linux clean
	cd libft && make clean && cd ..


fclean: clean
	cd libft && make fclean && cd ..

	rm -f ${NAME}   


re: fclean all
