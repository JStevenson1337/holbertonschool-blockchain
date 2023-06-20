
 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -c -Wno-deprecated-declarations

SRC = sha256.c ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify.c
OBJ = $(SRC:.c=.o)
NAME = libhblk_crypto.a

.PHONY: clean oclean flcean libhblk_crypto.a

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

libhblk_crypto.a: hblk_crypto.h $(OBJ)
	ar rcs $(NAME) $(OBJ)