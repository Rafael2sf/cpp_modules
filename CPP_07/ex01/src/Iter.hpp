#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void	iter(T *_src, size_t _len, void (*_f)( T const & ))
{
	size_t	i = 0;

	while (i < _len)
	{
		_f(_src[i]);
		i++;
	}
}

#endif /* ITER */
