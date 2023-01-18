SRCS_LIBFT	= ft_isdigit.c		\
			  ft_atoi.c			\
			  ft_strcmp.c		\
			  ft_min.c			\
			  ft_itoa.c			\
			  ft_memset.c 		\
			  ft_strchr.c 		\
			  ft_strcpy.c 		\
			  ft_strlen.c 		\
			  ft_strncpy.c 		\
			  ft_toupper.c		\
			  ft_strtoupper.c	\
			  ft_uitoa.c		\

SRCS_PRINTF	= ft_printf.c		\
			  parse.c			\
			  print.c			\
			  util.c			\
			  mode.c			\
			  flags.c			\
			  padding.c			\
			  convert.c			\
			  sort.c			\

SRCS		= operations.c		\
			  push_swap.c		\
			  rotate.c			\
			  revrotate.c		\
			  utils.c			\
			  stack.c			\
			  get.c				\
			  cost.c			\
			  quick_sort.c		\

OBJS_LIBFT	= $(addprefix libft/, $(SRCS_LIBFT:.c=.o))

OBJS_PRINTF	= $(addprefix printf/, $(SRCS_PRINTF:.c=.o))

OBJS		= $(addprefix srcs/, $(SRCS:.c=.o))

HEADER		= -I include/

CC			= cc

CFLAGS		= -g3 -Wall -Wextra -Werror

RM			= rm -f

MAIN		= main.c

LIBFT		= libft.a

LIB			= lib.a

NAME		= push_swap

AR			= ar rcs

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):	$(LIB) $(MAIN)
	$(CC) $(HEADER) $(CFLAGS) $(LIB) $(MAIN) -o $(NAME)

$(LIB):		$(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF)
	$(AR) $@ $^

all:		$(NAME)

bonus:		all

clean:
	$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF)

fclean:		clean
	$(RM) $(NAME) $(LIB) $(LIBFT)

re:		fclean all

.PHONY:		all bonus clean fclean re
