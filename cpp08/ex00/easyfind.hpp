#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template < typename T >
int	easyfind(const T &cnt, int target)
{
	if (std::find(cnt.begin(), cnt.end(), target) != cnt.end())
		return 0;
	throw std::runtime_error("Element not found");
}

#endif