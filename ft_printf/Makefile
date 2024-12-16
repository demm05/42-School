NAME = libftprintf.a
BINARY = out

HDIR = ./inc 
SDIR = ./srcs
ODIR = ./objs

SRCS := $(wildcard $(SDIR)/*.c)
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HDIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : all

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re run $(BINARY) a m b 

$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(BINARY) $^

run: $(BINARY)
	@clear
	./$(BINARY)
a:
	$(MAKE) -C ./printfTester a 
m:
	$(MAKE) -C ./printfTester m 
b:
	$(MAKE) -C ./printfTester b 
