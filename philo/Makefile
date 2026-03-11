GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m
ERASE  = \033[K

NAME = philo
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I$(INC_DIR)

SRC = $(addprefix src/, core/main.c \
						core/init.c \
						core/check_args.c \
						core/ft_msleep.c \
						core/get_current_time.c \
						core/ft_threads.c \
						core/observer.c \
						core/routine.c \
						core/print_action.c \
						core/everyone_alive.c \
						core/free_all.c \
						utils/ft_atoi.c \
						utils/ft_atoui.c \
						utils/ft_putstr_fd.c \
						utils/ft_isdigit.c \
						)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = inc/philo.h inc/ft_err.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\n$(GREEN)$(NAME) created$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\r$(ERASE)$(BLUE) compiled $(notdir $@)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)dir $(OBJ_DIR)/ created $(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(YELLOW)removed $(OBJ_DIR)/ dir$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YELLOW)removed $(NAME)$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
