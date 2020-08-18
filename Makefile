NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

GNLLIB = libgnl.a

GNLSRC = gnl/get_next_line.c \
		 gnl/get_next_line_utils.c

GNLOBJ = $(GNLSRC:.c=.o)

SRCS = srcs/minishell_main.c \
	   srcs/minishell_cd.c \
	   srcs/minishell_utils.c \
	   srcs/parsing_cmd.c \
	   srcs/builtins.c \
	   srcs/ft_split.c \
	   srcs/try_execute.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(GNLOBJ) : $(GNLSRC)
	$(CC) $(CFLAGS) -c $(GNLSRC)
	mv get* gnl/


$(GNLLIB): $(GNLOBJ)
	ar rcs $(GNLLIB) $(GNLOBJ)

$(NAME): $(OBJS) $(GNLLIB)
	$(CC) $(CFLAGS) -o $(NAME) -L. -lgnl $(SRCS)


clean :
	rm $(GNLOBJ) $(OBJS) $(GNLLIB)

fclean : clean
	rm $(NAME)

re : fclean all
