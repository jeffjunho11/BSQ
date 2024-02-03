CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c ft_atoi.c ft_split.c map_parse.c map.c read_text.c solve_map.c string_util.c

TARGET = bsq
HEADER = -I includes

OBJS =  $(SRCS:.c=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAG) $(HEADER) -o ${TARGET} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean  re
