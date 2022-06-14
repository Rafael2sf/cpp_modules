#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>

class	Span: protected std::list<int>
{
	public:
		~Span();
		Span( int );
		Span( Span const & );
		Span & operator=( Span const & );
		std::size_t getMaxSize( void ) const;
		void addNumber( int );
		long shortestSpan( void ) const;
		long longestSpan( void ) const;
		void print( std::ostream & o ) const;
		//std::insert()

	private:
		Span( void );
		std::size_t _max_size;
};

std::ostream & operator<<( std::ostream & o, Span const & rhs );

#endif /* SPAN_HPP */
