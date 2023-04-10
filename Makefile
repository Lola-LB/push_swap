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
			  main.c			\

OBJS_LIBFT	= $(addprefix srcs/libft/, $(SRCS_LIBFT:.c=.o))

OBJS_PRINTF	= $(addprefix srcs/printf/, $(SRCS_PRINTF:.c=.o))

OBJS		= $(addprefix srcs/, $(SRCS:.c=.o))

HEADER		= -I include/

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= push_swap

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF)
	@echo "Compiling..."
	@echo "Linking..."
	@$(CC) $(HEADER) $(CFLAGS) $(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF) -o $(NAME)
	@echo "Done!"

all:		$(NAME)

bonus:		all

clean:
	@echo "Removing objs..."
	@$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF)
	@echo "clean done!"

fclean:		clean
	@echo "Removing bin..."
	@$(RM) $(NAME)
	@echo "fclean done!"

re:		fclean all

.PHONY:		all bonus clean fclean re
