#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template< typename T >
long	easyfind( T _haystack, int _needle )
{
 	typename T::iterator result = std::find(_haystack.begin(), _haystack.end(), _needle);
	if (result != _haystack.end())
		return (std::distance(_haystack.begin(), result) + 1);
	return (0);
}

#endif /* EASYFIND_HPP */
