##
## EPITECH PROJECT, 2024
## B-PSU-200-NAN-2-1-minishell1-julien.paillard
## File description:
## Makefile
##


SRC = main.c \
      src/launch_terminal.c \
	  src/my_putchar.c \
	  src/my_putstr.c \
	  src/find_good_command.c \
	  src/my_strcmp.c \
	  src/my_strlen.c \
	  src/cd_command.c \
	  src/my_strcpy.c \
	  src/env_display_command.c \
	  src/my_strcat.c \
	  src/get_args.c \
	  src/my_strdup.c \
	  src/setenv_command.c \
	  src/unsetenv_command.c \
	  src/my_tabcpy.c \
	  src/len_tab.c \
	  src/create_linked_list.c \
	  src/get_env_char.c \
	  src/exit_command.c \
	  src/my_getnbr.c \
	  src/is_alphanumeric.c \
	  src/get_paths.c \
	  src/execute_good_status_command.c \
	  src/execute_good_status_binarie_command.c \
	  src/get_pwd.c \
	  src/my_puterr.c \
	  src/get_count.c \
	  src/contains_a_slash.c

OBJ = $(SRC:.c=.o)

NAME = mysh

##CFLAGS += -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
