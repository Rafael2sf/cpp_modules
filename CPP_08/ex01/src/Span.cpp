#include "Span.hpp"
#include <stdint.h>

Span::Span( void )
{
	this->_max_size = 0;
}

Span::~Span()
{}

Span::Span( Span const & ref ): list()
{
	*this = ref;
}

Span & Span::operator=( Span const & rhs )
{
	this->clear();
	this->_max_size = rhs.getMaxSize();
	if (!rhs.empty())
	{
		for (Span::list<int>::const_reverse_iterator it = rhs.rbegin(); it != rhs.rend(); it++)
			this->push_front(*it);
	}
	return (*this);
}

Span::Span( int n ): _max_size(n)
{}

std::size_t Span::getMaxSize( void ) const
{
	return (this->_max_size);
}

void Span::addNumber( int n )
{
	if (this->size() >= this->_max_size)
		throw std::length_error("list maximum size reached");
	list<int>::iterator it;
	if (this->size() > 0)
	{
		for (it = this->begin(); it != this->end(); it++)
		{
			if (static_cast<long>(*it) > n)
				break ;
		}
		insert(it, 1, n);
	}
	else
		this->push_front(n);
}

long Span::shortestSpan( void ) const
{
	if (this->size() < 2)
		throw std::length_error("not enought elements to calculate shortest span");
	long	span =				INT64_MAX;
	list<int>::const_iterator	tmp;

	tmp = this->begin();
	for (list<int>::const_iterator it = ++this->begin(); it != this->end(); it++)
	{
		if ((static_cast<long>(*it) - static_cast<long>(*tmp)) < span)
			span = static_cast<long>(*it) - static_cast<long>(*tmp);
		tmp = it;
	}
	return (span);
}

long Span::longestSpan( void ) const
{
	if (this->size() < 2)
		throw std::length_error("not enought elements to calculate longest span");
	return (static_cast<long>(this->back()) - static_cast<long>(this->front()));
}

void	Span::print( std::ostream & o ) const
{
 	o << "span: ( ";
	for (list<int>::const_iterator it = this->begin(); it != this->end(); it++)
		o << *it << " ";
	o << ")";
}

std::ostream & operator<<( std::ostream & o, Span const & ref )
{
	ref.print(o);
	return (o);
}
