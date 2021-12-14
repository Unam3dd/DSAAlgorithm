NAME = dsa
CFLAGS = -Wall -I includes
SRC = $(wildcard src/**/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME).a $^
	ranlib $(NAME).a

clean: $(OBJ)
	rm $^

fclean:	clean
	rm $(NAME).a