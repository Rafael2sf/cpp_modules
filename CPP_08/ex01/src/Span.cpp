#include "Span.hpp"

Span::Span( void )
{}

Span::~Span()
{}

Span::Span( Span const & ref )
{
	(void)ref;
}

Span & Span::operator=( Span const & rhs )
{
	// while rhs.... this.push n
	(void)rhs;
	return (*this);
}

Span::Span( int n )
{
	(void)n;
}

void Span::addNumber( int n )
{
	this->push_front(n);
}

int Span::shortestSpan( void )
{
	return (0);
}

int Span::longestSpan( void )
{
	return (0);
}
