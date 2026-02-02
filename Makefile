NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

STEP_ONE = parsing_part
STEP_TWO = operations_part
STEP_THREE = algo_part

SRCS_ONE = $(STEP_ONE)/free_clean.c \
           $(STEP_ONE)/ft_split_ft.c \
           $(STEP_ONE)/ft_split.c \
           $(STEP_ONE)/help_function.c \
           $(STEP_ONE)/input_handle.c

SRCS_TWO = $(STEP_TWO)/linked_list.c \
           $(STEP_TWO)/ops_push.c \
           $(STEP_TWO)/ops_rev_rotate.c \
           $(STEP_TWO)/ops_rotate.c \
           $(STEP_TWO)/ops_swap.c

SRCS_THREE = $(STEP_THREE)/smart_sort.c \
             $(STEP_THREE)/sort.c \
             $(STEP_THREE)/utils.c

SRCS_MAIN = main.c

SRCS = $(SRCS_MAIN) $(SRCS_ONE) $(SRCS_TWO) $(SRCS_THREE)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean