/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:38:16 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/31 18:00:41 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template < typename T >
int	easyfind(const T &cnt, int target)
{
	if (std::find(cnt.begin(), cnt.end(), target) != cnt.end())
		return 0;
	return 1;
	//// for (typename T::const_iterator start = cnt.begin(); start != cnt.end(); start++)
	//// {
	//// 	if (*start == target)
	//// 		return 0;
	//// }
}

#endif