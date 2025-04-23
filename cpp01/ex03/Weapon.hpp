/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:34:13 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 15:22:37 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class   Weapon {

private:
    std::string type;

public:
    Weapon( void );
    Weapon( const std::string& wName );
    ~Weapon ( void );
    const std::string&  getType( void ) const;
    void                setType( const std::string &newType );

};

