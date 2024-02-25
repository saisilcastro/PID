ifeq ($(OS),Windows_NT)
	CC = gcc
	NAME = run.exe
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
endif
INCLUDE = -I./include
VPATH = src: ./src
SRC = 	pid.c \
		main.c
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)

all: $(NAME)
$(NAME) : $(SRCOBJ)
	$(CC) $^ -o $(NAME)
${OBJ}/%.o : %.c
	$(call CREATE,${OBJ})
	$(CC) -c $< -o $@ $(INCLUDE)
clean:
	$(call REMOVE,${OBJ})
fclean: clean
	$(call REMOVE,${NAME})
re: fclean all