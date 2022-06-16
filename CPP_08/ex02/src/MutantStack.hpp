#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template < typename T >
class	MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	public:
		~MutantStack();
		MutantStack( void );
		MutantStack( MutantStack const & ref );
		MutantStack & operator=( MutantStack const & rhs );

		iterator begin( void );
		iterator end( void );
		reverse_iterator rbegin( void );
		reverse_iterator rend( void );
		const_iterator begin( void ) const;
		const_iterator end( void ) const;
		const_reverse_iterator rbegin( void ) const;
		const_reverse_iterator rend( void ) const;
};

template< typename T >
MutantStack<T>::~MutantStack()
{}

template< typename T >
MutantStack<T>::MutantStack( void )
{}

template< typename T >
MutantStack<T>::MutantStack( MutantStack<T> const & ref )
: std::stack<T>(ref)
{}

template < typename T >
MutantStack<T> & MutantStack<T>::operator=( MutantStack const & rhs )
{
	std::stack<T>::operator=(rhs);
	return (*this);
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
	return (std::stack<T>::c.begin());
}

template < typename T >
typename MutantStack<T>::iterator  MutantStack<T>::end( void )
{
	return (std::stack<T>::c.end());
}

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin( void )
{
	return (std::stack<T>::c.rbegin());
}

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend( void )
{
	return (std::stack<T>::c.rend());
}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const
{
	return (std::stack<T>::c.begin());
}

template < typename T >
typename MutantStack<T>::const_iterator  MutantStack<T>::end( void ) const
{
	return (std::stack<T>::c.end());
}

template < typename T >
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin( void ) const
{
	return (std::stack<T>::c.rbegin());
}

template < typename T >
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend( void ) const
{
	return (std::stack<T>::c.rend());
}

#endif /* MUTANTSTACK_HPP */
