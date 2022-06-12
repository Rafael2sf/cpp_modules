#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void	iter(T *_src, size_t _len, void (*_f)(int , T const & ))
{
	size_t	i = 0;

	while (i < _len)
	{
		_f(i, _src[i]);
		i++;
	}
}

#endif /* ITER */
