/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:32 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/12 09:24:17 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "This program takes only one parameter. Usage <./harlFilter OPTION>" << std::endl;
		return 1;
	}
	Harl	harlito;
	harlito.filter( argv[1] );

}
