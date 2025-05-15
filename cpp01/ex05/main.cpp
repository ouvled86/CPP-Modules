/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:29:02 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/12 09:10:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
	Harl	harlito;

	harlito.complain("DEBUG");
	harlito.complain("INFO");
	harlito.complain("WARNING");
	harlito.complain("ERROR");
	harlito.complain("MEOW");
}
