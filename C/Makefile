NAME	:= C-Algo

CFLAGS	:= -Wextra -Wall #-Werror

HEADERS	:= -I ./include

SRCDIR := ./src/
SRCS	:=  $(SRCDIR)main.c \
			$(SRCDIR)parsing.c

OBJDIR := ./obj/
OBJS	:= $(SRCS:%.c=$(OBJDIR)%.o)

CC		:= cc

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
