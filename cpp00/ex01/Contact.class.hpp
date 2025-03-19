/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:52:16 by codespace         #+#    #+#             */
/*   Updated: 2025/03/17 00:03:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <string>
# include <iostream>

typedef struct s_info
{

	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	num;
	std::string	secret;

}				t_info;

class Contact {
	
private:
	
	t_info	information;

public:
	
	Contact( void );
	Contact( t_info info );
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getNum();
	std::string	getSecret();
	
};

#endif