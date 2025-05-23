NAME		=	so_long
NAME_BONUS	=	so_long_bonus

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g $(SYSTEM)

# System Detection
MLXFLAGS =  -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

MDT_DIR		=	Mandatory/
BONUS_DIR	=	Bonus/

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

LIBFT		=	libft/libft.a

INC			=	$(addprefix $(MDT_DIR), $(INC_DIR))

INC_BONUS	=	$(addprefix $(BONUS_DIR), $(INC_DIR)) 

INCLUDE		+= -I $(INC) 
INCLUDE		+= -I $(INC_BONUS)


SL_SRCS	=		so_long.c check_valid_path.c checker.c end_screen.c \
				errors.c file_to_image.c ft_free.c \
				generate_map_array.c key_hook.c\
				map_printer.c movements.c \
				
SL_SRCS_BONUS	=	so_long_bonus.c animation_monster_bonus.c checker_bonus.c \
					errors_bonus.c file_to_image_bonus.c ft_free_bonus.c \
					generate_map_array_bonus.c key_hook_bonus.c \
					map_printer_bonus.c move_animation_bonus.c movements_bonus.c \
					movements_monster_bonus.c \
					scan_monster_bonus.c end_screen_bonus.c check_valid_path_bonus.c\

SRCS			+=	$(addprefix $(MDT_DIR), $(addprefix $(SRC_DIR), $(SL_SRCS)))
SRCS_BONUS		+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(SL_SRCS_BONUS)))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))
DEPS_BONUS		+=	$(addsuffix .d, $(basename $(OBJS_BONUS)))


$(OBJ_DIR)%.o : %.c Makefile
	@$(MD) $(dir $@)
	@make -sC mlx
	@make -sC libft
	@echo "$(WARN_COLOR)Compiling: $<$(NO_COLOR)"
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) $(INCLUDE) -Imlx   $< -o $@ 


all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS)  $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)
			@echo "$(OK_COLOR)So Long Compiled!$(NO_COLOR)"

bonus:		$(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			@$(CC) $(CFLAGS)  $(LIBFT) $(OBJS_BONUS) -o $(NAME_BONUS) $(MLXFLAGS)
			@echo "$(OK_COLOR)So Long Bonus Compiled!$(NO_COLOR)"
clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@$(RM) get_next_line/get_next_line.o
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -sC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all


-include $(DEPS)
-include $(DEPS_BONUS)


.PHONY: all bonus clean fclean re 


NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)


