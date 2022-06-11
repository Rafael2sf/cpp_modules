#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <limits>
#include <cerrno>

enum e_type
{
	TYPE_CHR,
	TYPE_INT,
	TYPE_FLT,
	TYPE_DBL,
	TYPE_UNK,
};

void	char_cast( const std::string & _s );
void	int_cast( const std::string & _s );
void	float_cast( const std::string & _s );
void	double_cast( const std::string & _s );

#endif
