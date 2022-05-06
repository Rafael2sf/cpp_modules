#
#	This script will create project folders and classes
#

# New exercise
# Run ./helper.sh new <folder_name> <executable_name>

# New Class
# Run ./helper.sh class <class_name> <destination>

# To make your own makefiile template, create a makefile
#  and run this cmd {{sed 's/\$/\\\$/g' Makefile > Makefile.template}}
# Replace NAME variable or similar with <insert_name>
# Then copy the contents to TEMPLATE variable

TEMPLATE="# PROGRAM #

NAME	=		<insert_name>

# TERMINAL #

RMV		=		rm -f
MKD		=		mkdir
PRT		=		printf
MKE		=		make
CPY		=		cp

# COLORS #

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

# DIRS #

_SRC	=		./src/
_OBJ	=		./objs/
_LIB	=

# COMPILER #

CC		=		c++
AR		=		ar rcs
CFLAGS	=		-Wall -Werror -Wextra -std=c++98

# FILES #

SRCS_	=		\
				main.cpp

SRCS	=		\$(addprefix \$(_SRC), \$(SRCS_))
OBJS	=		\$(patsubst \$(_SRC)%.cpp,\$(_OBJ)%.o,\$(SRCS))

# RULES #

all: \$(NAME)

\$(_OBJ)%.o: \$(_SRC)%.cpp
	\$(CC) \$(CF) -c \$< -o \$@

\$(NAME):  \$(_OBJ) \$(OBJS)
	\$(CC) \$(CFLAGS) \$(OBJS) -o \$(NAME)

# STRUCTURE #

\$(_OBJ):
	\$(MKD) \$@

\$(_LIB):
	\$(MKD) \$@

\$(_SRC):
	\$(MKD) \$@

# CLEAN #

clean:
	\$(RMV) \$(OBJS)

fclean: clean
	\$(RMV) -r \$(_OBJ) \$(NAME)

re: fclean all

.PHONY: all clean fclean re"

MAIN="#include <iostream>\n\nint main(void)\n{\n\treturn (0);\n}"

show_usage()
{
	printf "Usage: \n\tnew <folder_path> <name>\n\tclass <name>\n"
}

if [ "$1" ] && [ $1 == "new" ]
then
	if [ "$2" ] && mkdir "./$2"
	then
		if [ "$3" ]
		then
			echo "$TEMPLATE" | sed 's/\\\$/\$/g' | sed "s/<insert_name>/$3/g" > $2/Makefile
			mkdir $2/src
			echo "$MAIN" > $2/src/main.cpp
			exit 0
		fi
		echo "error: invalid name: $3"
		exit 1
	fi
	echo "error: failed to create directory: $2"
	exit 1
elif [ "$1" ] && [ $1 == "class" ]
then
	if [ "$3" ]
	then
		echo "TO DO CLASS"
		exit 0
	fi
	echo "error: missing name"
	exit 1
else
	show_usage
fi
