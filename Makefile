UTILSPATH = ./utilities
SRCSPATH  = ./src
GNLPATH		= ./get_next_line

UTILS = $(UTILSPATH)/list_utilities.c $(UTILSPATH)/helpers.c $(UTILSPATH)/pipe_utils.c $(UTILSPATH)/split_arguments_list_utils.c $(UTILSPATH)/spl_args_utils.c
SRCS =  $(SRCSPATH)/commands.c $(SRCSPATH)/redirection.c $(SRCSPATH)/processes.c $(SRCSPATH)/split_arguments.c
GNL = $(GNLPATH)/get_next_line.c $(GNLPATH)/get_next_line_utils.c

UTILOBJS = $(UTILS:.c=.o)
SRCOBJS  = $(SRCS:.c=.o)
GNLOBJS  = $(GNL:.c=.o)
OBJS = $(UTILOBJS) $(SRCOBJS) $(GNLOBJS)
PATH := @$(shell echo $$PATH)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex
LIBR = pipex.a
PRINTFPATH = ./ft_printf
PRINTFLIB  = $(PRINTFPATH)/libftprintf.a


%.o: %.c
	@$(CC) $(CFLAGS) -DPTH=\"$(PATH)\" -c $< -o $@

$(NAME): main.c $(LIBR)
	@$(CC) $(CFLAGS) main.c $(LIBR) -g -o $(NAME)
	@echo "Build complete"

all: $(NAME)

$(PRINTFLIB):
			@make -s -C $(PRINTFPATH)

$(LIBR): $(PRINTFLIB) $(OBJS)
		@cp $(PRINTFLIB) $(LIBR)
		@ar rcs $(LIBR) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(LIBR)
		@make -s -C $(PRINTFPATH) fclean
		@echo "Clean Complete"

re: fclean $(NAME)

.PHONY: fclean all re clean
