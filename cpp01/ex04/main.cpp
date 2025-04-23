/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:20:30 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 19:52:50 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

int replaceStrings( const std::string &fname, const std::string &oldStr, const std::string &newStr ) {

    std::ifstream   in( fname );
    if ( !in ) {

        std::cerr << "./replace cannot open input file: " << fname << std::endl;
        return 1;

    }
    std::string buff( (std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>() );
    in.close();
    std::string buff2;
    size_t  i = 0;
    size_t  findI = buff.find( oldStr, i );
    while ( findI != std::string::npos ) {
        
        buff2.append( buff, i, findI - i );
        buff2.append( newStr );
        i = findI + oldStr.length();
        findI = buff.find( oldStr, i );

    }
    buff2.append( buff, i, std::string::npos );
    std::string newFile = fname + ".replace";
    std::ofstream   out( newFile );
    if ( !out ) {
        
        std::cerr << "./replace cannot create output file: " << fname + ".replace" << std::endl;
        return 1;

    }
    out << buff2;
    out.close();
    return 0;

}

int main( int argc, char **argv) {

    if ( argc != 4 ) {
        std::cerr << "This program takes 4 arguments. Usage: ./replace <filename> <old_string> <new_string>" << std::endl;
        return 1;
    }
    return replaceStrings( argv[1], argv[2], argv[3] );

}
