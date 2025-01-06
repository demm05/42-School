BIN = push_swap

HDIR = ./include
SDIR = ./srcs
ODIR = ./objs

LIB_DIR = ./printf
LIB = $(LIB_DIR)/libftprintf.a

C_SRCS := $(wildcard $(SDIR)/*.c)
C_OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(C_SRCS))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I $(HDIR)

all: directories $(LIB) $(BIN) 

$(BIN): $(C_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB):
	$(MAKE) -C $(LIB_DIR) 

bonus: all

directories:
	$(shell mkdir -p $(ODIR))
	$(shell mkdir -p $(ODIR)/client)
	$(shell mkdir -p $(ODIR)/server)

clean:
	@rm -rf $(ODIR)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re directories 
