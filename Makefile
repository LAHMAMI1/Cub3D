



.PHONY = all clean fclean re

NAME = cub3D
BONNUS_NAME = cub3D_bonus

CC = gcc
CFLAGS = -Iminilibx-linux 
CFLAGS += -fsanitize=address -g3 
CFLAGS += -Wall -Werror -Wextra 

RC_F = raycasting
RC_B_F = raycasting_bonnus
GNL = Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c
PARS = parsing/parsing.c parsing/check_args.c parsing/check_all.c parsing/read.c parsing/check_empty.c parsing/identifiers.c parsing/colors.c parsing/map.c parsing/check_wall.c parsing/utils.c
RC = $(RC_F)/draw_2d_map.c $(RC_F)/mlx_utils.c $(RC_F)/hooks_handler.c $(RC_F)/draw_line.c $(RC_F)/find_wall.c $(RC_F)/texturs.c $(RC_F)/cub3D_util.c $(RC_F)/update_player.c $(RC_F)/draw_3D_map.c
RC_B = $(RC_B_F)/draw_2d_map.c $(RC_B_F)/mlx_utils.c $(RC_B_F)/hooks_handler.c $(RC_B_F)/draw_line.c $(RC_B_F)/find_wall.c $(RC_B_F)/texturs.c $(RC_B_F)/cub3D_util.c $(RC_B_F)/update_player.c $(RC_B_F)/draw_3D_map.c

SRC = cub3D.c $(RC) $(PARS) $(GNL)
SRC_B = cub3D.c $(RC_B) $(PARS) $(GNL)

OBJS = ${SRC:%.c=%.o}
OBJS_BONUS = ${SRC_B:%.c=%.o}

all : ${NAME}

${NAME} : ${OBJS}
	cd libft && make && make bonus && cd .. 
	make -C minilibx-linux  
	$(CC) $(CFLAGS)  -o ${NAME} ${OBJS} libft/libft.a -L./minilibx-linux -lm -lmlx -lXext -lX11
	
bonus : ${OBJS_BONUS}
	cd libft && make && make bonus && cd .. 
	make -C minilibx-linux  
	$(CC) $(CFLAGS)  -o ${BONNUS_NAME} ${OBJS_BONUS} libft/libft.a -L./minilibx-linux -lm -lmlx -lXext -lX11


clean:
	rm -rf ${OBJS}	${OBJS_BONUS}
	make -C minilibx-linux clean
	cd libft && make clean && cd ..


fclean: clean
	cd libft && make fclean && cd ..

	rm -f ${NAME}   
	rm -f ${BONNUS_NAME}


re: fclean all
