CLIENT = client
SERVER = server

HDIR = ./include
SDIR = ./srcs
ODIR = ./objs

LIBFT = ./ft_printf/libftprintf.a

E_SRCS := $(wildcard $(SDIR)/*.c)
C_SRCS := $(wildcard $(SDIR)/client/*.c)
S_SRCS := $(wildcard $(SDIR)/server/*.c)
E_OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(E_SRCS)) 
C_OBJS := $(patsubst $(SDIR)/client/%.c, $(ODIR)/client/%.o, $(C_SRCS))
S_OBJS := $(patsubst $(SDIR)/server/%.c, $(ODIR)/server/%.o, $(S_SRCS))


CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(HDIR)


all: directories $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJS) $(E_OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(S_OBJS) $(E_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./ft_printf/ 

bonus: all

directories:
	$(shell mkdir -p $(ODIR))
	$(shell mkdir -p $(ODIR)/client)
	$(shell mkdir -p $(ODIR)/server)

clean:
	@rm -rf $(ODIR)
	@$(MAKE) -C ./ft_printf/ clean

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)
	@$(MAKE) -C ./ft_printf/ fclean

re: fclean all

.PHONY: all bonus clean fclean re directories 
