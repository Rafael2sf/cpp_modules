#!/bin/bash

#
#	This script will create project folders and classes
#

# New exercise
#	Run ./helper.sh new <folder_name> <executable_name>

# New Class
#	Run ./helper.sh class <class_name> <destination>

# To make your own makefiile template, create a makefile
#  and run this cmd {{ sed 's/\$/\\\$/g' Makefile > Makefile.template }}
# Replace executable name with <insert_name>
# Then copy the contents to TEMPLATE variable

# Usage 
# -----

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

SRCS_	=		main.cpp

SRCS	=		\$(addprefix \$(_SRC), \$(SRCS_))
OBJS	=		\$(patsubst \$(_SRC)%.cpp,\$(_OBJ)%.o,\$(SRCS))

# RULES #

all: \$(NAME)

\$(_OBJ)%.o: \$(_SRC)%.cpp
	\$(CC) \$(CFLAGS) -c \$< -o \$@

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
			if [ "$TEMPLATE" ]
			then
				printf "$TEMPLATE" | sed 's/\\\$/\$/g' | sed "s/<insert_name>/$3/g" > $2/Makefile
			else
				printf "Warning: no makefile template provided, skipping...\n"
			fi
			if [ ! "$(mkdir $2/src)" ]
			then
				printf "$MAIN" > $2/src/main.cpp
			fi
			exit 0
		fi
		printf "error: invalid name: $3"
		exit 1
	fi
	#printf "error: failed to create directory: $2"
	exit 1
elif [ "$1" ] && [ $1 == "class" ]
then
	if [ "$2" ]
	then
		printf ">> Type ENTER or CTRL+D to ignore\n"
		touch $2.cpp $2.hpp
		# Add header guard
		upper=$(printf "$2" | awk '{print toupper($0)}')
		printf "#ifndef ${upper}_HPP\n# define ${upper}_HPP\n\n" >> $2.hpp
		# Add headers
		printf "Headers\n"
		while [ 1 ]
		do
			read -e -p "$ " i
			if [ ! "$i" ];
			then
				break
			fi
			if [ "$(printf "$i" | grep \")" ];
			then
				printf "# include ${i}\n" >> $2.hpp
			else
				printf "# include <${i}>\n" >> $2.hpp
			fi
			i=""
		done

		# Class
		printf "\nclass\t$2\n{\n\tpublic:\n\t\t${2}( void );\n\t\t~${2}();\n" >> $2.hpp
		printf "\t\t${2}( ${2} const & );\n\t\t${2} & operator=( ${2} const & );\n" >> $2.hpp
		printf "#include \"${2}.hpp\"\n\n${2}::${2}( void )\n{}\n\n${2}::~${2}()\n{}\n\n" >> $2.cpp
		printf "${2}::${2}( ${2} const & )\n{}\n\n${2} & ${2}::operator=( ${2} const & )\n{}\n" >> $2.cpp
		static_vars=()
		# Public
		printf "Public\n"
		while [ 1 ]
		do
			read -e -p "$ " i
			if [ ! "$i" ];
			then
				break
			fi
			if [ "${i:0:1}" == "(" ];
			then
				printf "\t\t$2$i;\n" >> $2.hpp
				printf "\n$2::$2$i\n{}\n" >> $2.cpp
			elif [ "$(printf "$i" | grep \()" ];
			then
				arg=($i)
				for ((x = 0; x < ${#arg[*]}; x++))
				do
					if [ $x -eq 0 ];
					then
						if [ "${arg[$x]}" == "static" ];
						then
							((x = x + 1))
						fi
						printf "\t\t$i;\n" >> $2.hpp
						printf "\n${arg[$x]} $2::" >> $2.cpp
					else
						printf "${arg[$x]}" >> $2.cpp
					fi
				done
				printf "\n{}\n" >> $2.cpp
			else
				printf "\t\t$i;\n" >> $2.hpp
			fi
			if [ ! "$(printf "$i" | grep \()" ] && [ "${i:0:7}" == "static " ];
			then
				static_vars+="$i"
			fi
			i=""
		done

		# Private
		printf "\n\tprivate:\n" >> $2.hpp
		printf "Private\n"
		while [ 1 ]
		do
			read -e -p "$ " i
			if [ ! "$i" ];
			then
				break
			fi
			if [ "${i:0:1}" == "(" ];
			then
				printf "\t\t$2$i;\n" >> $2.hpp
				printf "\n$2::$2$i\n{}\n" >> $2.cpp
			elif [ "$(printf "$i" | grep \()" ];
			then
				arg=($i)
				for ((x = 0; x < ${#arg[*]}; x++))
				do
					if [ $x -eq 0 ];
					then
						if [ "${arg[$x]}" == "static" ];
						then
							((x = x + 1))
						fi
						printf "\t\t$i;\n" >> $2.hpp
						printf "\n${arg[$x]} $2::" >> $2.cpp
					else
						printf "${arg[$x]}" >> $2.cpp
					fi
				done
				printf "\n{}\n" >> $2.cpp
			else
				printf "\t\t$i;\n" >> $2.hpp
			fi
			if [ ! "$(printf "$i" | grep \()" ] && [ "${i:0:7}" == "static " ];
			then
				static_vars+="$i"
			fi
			i=""
		done

		# More then one static variable is not workig
		for ((x = 0; x < ${#static_vars[*]}; x++))
		do
			j=(${static_vars[x]})
			printf "\n${j[1]} ${2}::${j[2]} = 0;\n" >> $2.cpp
		done

		# End
		printf "};\n\n#endif /* ${upper}_HPP */\n" >> $2.hpp
		exit 0
	fi
	printf "error: missing name"
	exit 1
else
	show_usage
fi
