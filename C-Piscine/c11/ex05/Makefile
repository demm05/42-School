SDIR = ./srcs
ODIR = ./objs
HDIR = ./includes

SRCS := $(wildcard $(SDIR)/*.c)
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

BINARY = do-op

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDIR)

all: directories $(BINARY)

$(BINARY): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

directories: 
	@mkdir -p $(ODIR)
	@mkdir -p $(SDIR)
	@mkdir -p $(HDIR)

.PHONY: all clean fclean

clean:
	rm -f $(ODIR)/*.o

fclean: clean
	rm -f $(BINARY)

re: fclean $(BINARY)