NAME = ftprintf.a

CC = gcc

SRC = 	printf.c print.c fct.c \
		fct2.c write.c read.c \
		format.c print_tp.c spec_d.c \
		
OBJ = $(addprefix $(ODIR),$(SRC:.c=.o))

FLG = -Wall -Werror -Wextra

SDIR = ./src/
ODIR = ./obj/
IDIR = ./includes/

all: mkobj $(NAME)

mkobj: 
	mkdir -p $(ODIR)

$(ODIR)%.o:$(SDIR)%.c
	$(CC) $(FLG) -I $(IDIR) -o $@ -c $<

mklib:
	make -C libft/

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all