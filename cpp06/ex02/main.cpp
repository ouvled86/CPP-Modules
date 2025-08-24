/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:50:06 by ouvled            #+#    #+#             */
/*   Updated: 2025/08/24 20:10:52 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{

	Base	*holder1 = generate();
	identify(holder1);
	delete (holder1);
	
	holder1 = generate();
	identify(holder1);
	delete (holder1);
	
	holder1 = generate();
	Base	&holder2 = *holder1;
	identify(holder2);
	delete (holder1);
	
	holder1 = generate();
	holder2 = *holder1;
	identify(holder2);
	delete (holder1);

}