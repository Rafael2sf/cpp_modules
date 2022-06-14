# PROGRAM #

NAME	=		container

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

CXX		=		c++
AR		=		ar rcs
CXXFLAGS=		-Wall -Werror -Wextra -std=c++98

# FILES #

SRCS_	=		main.cpp

SRCS	=		$(addprefix $(_SRC), $(SRCS_))
OBJS	=		$(patsubst $(_SRC)%.cpp,$(_OBJ)%.o,$(SRCS))
DEPENDS	=		$(patsubst $(_SRC)%.cpp,$(_OBJ)%.d,$(SRCS))

# RULES #

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(NAME):  $(_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPENDS)

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
