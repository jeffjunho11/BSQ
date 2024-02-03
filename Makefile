CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = src/main.c src/dic_apply.c src/dic_util.c src/dic.c src/ft_split.c src/ft_split_trim.c src/ft_strjoin.c src/map_parse.c src/map.c src/read_text src/solve_map.c src/string_util.c

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
