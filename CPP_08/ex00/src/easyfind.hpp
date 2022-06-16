#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template< typename T >
typename T::iterator	easyfind( T & _haystack, int _needle )
{
	return (std::find(_haystack.begin(), _haystack.end(), _needle));
}

#endif /* EASYFIND_HPP */
