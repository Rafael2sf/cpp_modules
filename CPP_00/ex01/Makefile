# PROGRAM #

NAME	=		phonebook

# TERMINAL #

RMV		=		rm -f
MKD		=		mkdir
PRT		=		printf
MKE		=		make
CPY		=		cp

# COLORS #

--GRN	=		[32m
--RED	=		[31m
--WHT	=		[39m

# DIRS #

_SRC	=		./src/
_OBJ	=		./objs/
_LIB	=

# COMPILER #

CC		=		c++
AR		=		ar rcs
CFLAGS	=		-Wall -Werror -Wextra -std=c++98

# FILES #

SRCS_	=		main.cpp \
				PhoneBook.cpp \
				Contact.cpp

SRCS	=		$(addprefix $(_SRC), $(SRCS_))
OBJS	=		$(patsubst $(_SRC)%.cpp,$(_OBJ)%.o,$(SRCS))
INCS	=		-I ./src

# RULES #

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.cpp
	$(CC) $(CF) -c $< -o $@

$(NAME):  $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS)

# STRUCTURE #

$(_OBJ):
	$(MKD) $@

$(_LIB):
	$(MKD) $@

$(_SRC):
	$(MKD) $@

# CLEAN #

clean:
	$(RMV) $(OBJS)

fclean: clean
	$(RMV) -r $(_OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
