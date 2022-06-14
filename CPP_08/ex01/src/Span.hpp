#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>

class	Span: protected std::list<int>
{
	public:
		~Span();
		Span( int );
		Span( Span const & );
		Span & operator=( Span const & );
		void addNumber( int );
		int shortestSpan( void );
		int longestSpan( void );
		// insert ()

	private:
		Span( void );
		size_t _size;
};

#endif /* SPAN_HPP */
