NAMEBONUS	=	cub3D_bonus
NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
BONUSLFT	=	bonus/libraries/libft/libft.a
INC			=	-I ./src -I ./libft -I ./mlx
INCBONUS		=	-I ./bonus/src -I ./bonus/libraries/libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lX11 -lXext -lXrandr -lXrender -lm -lXfixes -lbsd
LIBONUS		=	-L ./bonus/libraries/libft -lft -L ./mlx -lmlx -lX11 -lXext -lXrandr -lXrender -lm -lXfixes -lbsd
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m
SRC			=	src/cub3d.c \
				src/events.c \
				src/update.c \
				src/root_init.c \
				src/debug.c \
				src/move/move.c \
				src/move/ca_player_move.c \
				src/dispaly_debug.c \
				src/raycaster/draw.c \
				src/raycaster/raycasting.c \
				src/raycaster/calculate_and_draw_line.c \
				src/raycaster/set_texture_index.c \
				src/frees/free.c \
				src/frees/close_cub.c \
				src/init/game_init.c \
				src/init/run_root.c \
				src/init/get_texture.c \
				src/init/init_structur.c \
				src/parsing/parsing_color.c \
				src/parsing/parse.c \
				src/parsing/parsing_textures.c \
				src/parsing/parsing_map.c \
				src/parsing/get_mapfile_info.c \
				src/parsing/is_openble_file.c \
				src/parsing/parse_rgb.c \
				src/parsing/map_processing.c \
				src/maps/map.c \
				src/maps/map1.c \
				src/utils/util.c \
				
SRCBONUS	=	bonus/src/valids_bonus.c \
				bonus/src/gets_bonus.c \
				bonus/src/exit_bonus.c \
				bonus/src/free_bonus.c \
				bonus/src/firearm_bonus.c \
				bonus/src/handlers_bonus.c \
				bonus/src/init_bonus.c \
				bonus/src/main_bonus.c \
				bonus/src/map_bonus.c \
				bonus/src/map_validations1_bonus.c \
				bonus/src/map_validations2_bonus.c \
				bonus/src/mini_map_bonus.c \
				bonus/src/move_bonus.c \
				bonus/src/raycaster_bonus.c \
				bonus/src/render_textures_bonus.c \
				bonus/src/rotate_bonus.c \
				bonus/src/scene_bonus.c \
				bonus/src/start_game_bonus.c \
				bonus/src/support_bonus.c \
				bonus/src/utils_bonus.c 

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
			@$(CC) $(CFLAGS) -o $@ $^ $(LIB)
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"

$(NAMEBONUS):	$(OBJBONUS)
			@echo "$(RED)[ .. ] Compiling Bonus..$(RESET)"
			@$(CC) $(CFLAGS) -o $@ $^ $(LIBONUS)
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Bonus Ready!$(RESET)"

$(MLX):
			@echo "$(RED)[ .. ] | Compiling minilibx..$(RESET)"
			@make -s -C mlx
			@echo "$(GREEN)[ OK ]$(RESET)|$(YELLOW)Minilibx ready!$(RESET)"


$(LFT):
			@echo "$(RED)[ .. ] Compiling Libft..$(RESET)"
			@make -s -C libft
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Libft ready!$(RESET)"

$(BONUSLFT):
			@echo "$(RED)[ .. ] Compiling Bonus Libft..$(RESET)"
			@make -s -C bonus/libraries/libft
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Bonus Libft ready!$(RESET)"

$(OBJ): src/%.o: src/%.c $(LFT)
			@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJBONUS): bonus/src/%.o: bonus/src/%.c $(BONUSLFT)
			@$(CC) $(CFLAGS) $(INCBONUS) -o $@ -c $<

bonus:		$(MLX) $(BONUSLFT) $(NAMEBONUS)			


clean:
			@make -s $@ -C libft
			@make -s $@ -C bonus/libraries/libft
			@rm -rf $(OBJ) src/*.o
			@rm -rf $(OBJBONUS) bonus/src/*.o
			@echo "Object files removed."

fclean:		clean
			@make -s $@ -C libft
			@make -s $@ -C bonus/libraries/libft
			@rm -rf $(NAME)
			@rm -rf $(NAMEBONUS)
			@echo "Binary file removed."

re:			fclean all

rebonus:	fclean bonus
.PHONY:		all clean fclean re
