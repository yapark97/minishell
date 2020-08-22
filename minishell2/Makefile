NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

GNLSRC = gnl/get_next_line.c \
		 gnl/get_next_line_utils.c

GNLOBJ = $(GNLSRC:.c=.o)

SRCS = srcs/main.c \
	srcs/signals.c \
	srcs/exit.c \
	srcs/minishell_utils.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

#$(GNLOBJ) : $(GNLSRC)
#	$(CC) $(CFLAGS) -c $(GNLSRC)
#	mv get* gnl/


# $(GNLLIB): $(GNLOBJ)
# 	ar rcs $(GNLLIB) $(GNLOBJ)

# $(NAME): $(OBJS) $(GNLLIB)
# 	$(CC) $(CFLAGS) -o $(NAME) -L. -lgnl $(SRCS)

$(NAME): $(OBJS) $(GNLOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(GNLSRC)


clean :
	rm $(GNLOBJ) $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all
