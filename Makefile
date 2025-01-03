LIBFT_DIR = libraries/libft-main/
LIBFT_LIB = $(LIBFT_DIR)libft.a
#PRINTF_DIR = $(LIBFT_DIR)/ft_printf
#GNL_DIR = $(LIBFT_DIR)get_next_line/
#GNL_LIB = $(GNL_DIR)gnl.a

MLX_DIR = libraries/minilibx-linux/
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC = cc
GCC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

BONUS_NAME = cub3D_bonus
BONUS_OBJ_DIR = ./objs_bonus/
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:.c=.o))
BONUS_SRC_DIR = ./bonus/
BONUS_SRC = main_bonus.c memory_bonus/free_bonus.c memory_bonus/init_bonus.c start_bonus/start_game_bonus.c parsing_bonus/support_bonus.c \
	  parsing_bonus/scene_bonus.c parsing_bonus/elements_bonus.c parsing_bonus/elements2_bonus.c \
	  parsing_bonus/map_bonus.c parsing_bonus/map_validations1_bonus.c raycaster_bonus/raycaster_bonus.c\
	  events_bonus/exit_bonus.c events_bonus/handlers_bonus.c raycaster_bonus/render_textures_bonus.c\
	  events_bonus/move_bonus.c parsing_bonus/map_validations2_bonus.c bonus/mini_map_bonus.c events_bonus/rotate_bonus.c\
	  utils_bonus/utils_bonus.c bonus/gun_bonus.c


all : mlx_compile $(BONUS_NAME)

mlx_compile : 
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "Compiled MiniLibX!"

$(LIBFT_LIB) : $(LIBFT_DIR) #$(PRINTF_DIR) $(GNL_DIR)
	@make -C $(LIBFT_DIR) bonus #> /dev/null 2>&1
	#@make -C $(PRINTF_DIR) > /dev/null 2>&1
	#@make -C $(GNL_DIR) > /dev/null 2>&1
	@echo "Compiled LIBFT!"

clean:
	@$(RM) -rf $(OBJ_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) > /dev/null 2>&1
	@echo "Objects Cleaned!"

fclean:
	@$(RM) -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) > /dev/null 2>&1
	@$(RM) $(BONUS_NAME) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "Objects Full cleaned!"

re : fclean all
	@echo "Project Re-compiled!"


bonus : mlx_compile $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(dir $@) > /dev/null 2>&1
	@$(GCC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT_LIB)
	@$(GCC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_LIB) $(MLXFLAGS) -o $(BONUS_NAME)
	@echo "Compiled Bonus project!"

bonus : mlx_compile $(BONUS_NAME)

.SILENT : all