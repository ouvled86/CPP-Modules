/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:41:04 by codespace         #+#    #+#             */
/*   Updated: 2025/05/08 11:59:20 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact( void )
{
	t_info  info;
	info.fname = "N/A";
	info.lname = "N/A";
	info.nname = "N/A";
	info.num = "N/A";
	info.secret = "N/A";
	this->information = info;
	return ;
}

Contact::Contact( t_info info ) : information(info)
{
	return ;
}

std::string Contact::getFirstName( void )
{
	return this->information.fname;
}

std::string Contact::getLastName( void )
{
	return this->information.lname;
}

std::string Contact::getNickName( void )
{
	return this->information.nname;
}

std::string Contact::getNum( void )
{
	return this->information.num;
}

std::string Contact::getSecret( void )
{
	return this->information.secret;
}
