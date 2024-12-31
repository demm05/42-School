CLIENT = client
SERVER = server

HDIR = ./include
SDIR = ./srcs
ODIR = ./objs

LIBFT = ./libftprintf.a

C_SRCS := $(wildcard $(SDIR)/client/*.c)
S_SRCS := $(wildcard $(SDIR)/server/*.c)
C_OBJS := $(patsubst $(SDIR)/client/%.c, $(ODIR)/client/%.o, $(C_SRCS))
S_OBJS := $(patsubst $(SDIR)/server/%.c, $(ODIR)/server/%.o, $(S_SRCS))


CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(HDIR)

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(ODIR)/client)
$(shell mkdir -p $(ODIR)/server)

all: $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(S_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./ft_printf/ 

clean:
	@rm -rf $(ODIR)
	@$(MAKE) -C ./ft_printf/ clean

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)
	@$(MAKE) -C ./ft_printf/ fclean

re: fclean all

.PHONY: all bonus clean fclean re 
