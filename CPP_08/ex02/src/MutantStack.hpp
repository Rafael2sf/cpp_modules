#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template< class T >
class MutantStack;

template < typename T >
class MutantStackIterator
{
	public:
		MutantStackIterator( void )
			: _ref(NULL), _pos(0) {}
		MutantStackIterator( MutantStack< T > * ref )
			: _ref(ref), _pos(0) {}
		MutantStackIterator( MutantStack< T > * ref, size_t pos )
			: _ref(ref), _pos(pos) {}
		~MutantStackIterator()
			{}
		/*
		bool operator==( const MutantStackIterator & rhs ) const
			{ return (this->_pos == rhs._pos); }
		bool operator!=( const MutantStackIterator & rhs ) const
			{ return (this->_pos != rhs._pos); }
		MutantStackIterator & operator++( void ) { this->_pos++; return (*this); }
		MutantStackIterator operator++( int dummy )
			{ ( void )dummy; MutantStackIterator tmp = *this; ++*this; return (tmp); }
		MutantStackIterator & operator--( void ) { this->_pos--; return (*this); }
		MutantStackIterator operator--( int dummy )
			{ ( void )dummy; MutantStackIterator tmp = *this; --*this; return (tmp); }
		*/
		T & operator*( void )
			{ return (this->_ref[_pos]); }

	private:
		MutantStack< T > * _ref;
		size_t _pos;
};

template < typename T >
class	MutantStack: public std::stack<T>
{
	public:
		typedef MutantStackIterator<T> iterator;
		MutantStack( void ) {}
		~MutantStack() {}
		// MutantStack( MutantStack const & )
		// {}
		// MutantStack & operator=( MutantStack const & )
		// {}

		T & operator[]( std::size_t idx ) { return (this->c.at(idx)); }
		iterator begin( void ) { return (iterator(this, 0)); }
		iterator end( void ) { return (iterator(this, this->size())); }
		void test( void )
		{}
};

#endif /* MUTANTSTACK_HPP */
