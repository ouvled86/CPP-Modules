/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:52:27 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 07:03:40 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.class.hpp"

class PhoneBook {

private:
	
	int	index;
	Contact list[8];
	
public:


	int		getIndex(void) const;
	void	incrementSize(void);
	void	addContact(void);
	void	searchContact(void);
	// void	exitPhoneBook(void);
	PhoneBook(void);

};

void		get_str(std::string &buff, std::string str);
std::string	resizeString(std::string s);

#endif