# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:30:10 by jsabound          #+#    #+#              #
#    Updated: 2023/11/04 15:48:08 by jsabound         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = objs
SRCS_DIR = $(shell find srcs -type d)
INCLUDE		= ./

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir))
SRCS =	main.c get_file.c fill_map.c check_element.c\
		ft_malloc.c get_next_line.c get_next_line_utils.c\
				exec.c check_file.c error.c get_map.c path_finding.c\
					draw.c calcul.c get_player_pos.c key_press.c key_press2.c\
						set_image.c check_element2.c check_borders.c get_element.c draw2.c\
					
				
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

DEPS = $(OBJS:.o=.d)

FILE_TO_CHECK = "Makefile.gen"

NAME = cub3D
NORM = norminette

########################### COMPILATION AND FLAGS ###########################

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -MMD #-fsanitize=address

##################################### COLOR ##################################

COLOUR_PURPLE = \033[0;35m
COLOUR_END = \033[0m

##################################### MAIN ###################################

all: $(NAME)

##################################### MANDATORY ##############################

-include $(DEPS)

$(NAME): $(OBJS)
	cd libft && make
	cd minilibx-linux && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/ libft/libft.a
	@echo "\033[1;32mCompilation terminée avec succès.\033[0m"

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_DIR):
	mkdir -p $@
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

clean:
	cd libft && make fclean
	cd minilibx-linux && make clean
	$(RM) $(OBJS) $(OBJSBONUS) $(DEPS) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS) $(DEPS)

norm:
	@echo "$(COLOUR_PURPLE)***CHECK NORM FILES***$(COLOUR_END)"
	@$(NORM)
	
re: fclean all

.PHONY: all clean fclean re