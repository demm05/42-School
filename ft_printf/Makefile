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

$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $^

.PHONY: all clean fclean re $(BINARY) a m b 

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

a:
	$(MAKE) -C ./printfTester a 
m:
	$(MAKE) -C ./printfTester m 
b:
	$(MAKE) -C ./printfTester b 
