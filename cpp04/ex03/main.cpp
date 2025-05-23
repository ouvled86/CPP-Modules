/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouvled <ouvled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:12:03 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/05/23 21:27:10 by ouvled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>
#include <cassert>

// Utility function to print test header
void printTestHeader(const std::string &testName)
{
    std::cout << "\n===== " << testName << " =====\n";
}

// Test Materia Source functionality
void testMateriaSource()
{
    printTestHeader("MateriaSource Test");

    // Create MateriaSource
    IMateriaSource *src = new MateriaSource();

    // Learn Materias
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // Test creating known Materias
    AMateria *iceMateria = src->createMateria("ice");
    AMateria *cureMateria = src->createMateria("cure");

    // assert(iceMateria != NULL);
    // assert(cureMateria != NULL);

    // assert(iceMateria->getType() == "ice");
    // assert(cureMateria->getType() == "cure");

    // Test creating unknown Materia
    AMateria *unknownMateria = src->createMateria("unknown");
    assert(unknownMateria == NULL);

    // Test learning too many Materias
//    src->learnMateria(new Ice());
//    src->learnMateria(new Cure());
//    src->learnMateria(new Ice()); // This should not crash or cause undefined behavior

    // Cleanup
    delete iceMateria;
    delete cureMateria;
    delete src;

    std::cout << "MateriaSource Test Passed!\n";
}

// Test Character functionality
void testCharacter()
{
    printTestHeader("Character Test");

    // Create Character
    Character *me = new Character("Player");
    Character *bob = new Character("Bob");

    // Create Materias
    AMateria *ice1 = new Ice();
    AMateria *ice2 = new Ice();
    AMateria *cure1 = new Cure();
    AMateria* cure2 = new Cure();

    // Test equipping Materias
    (void)ice2;
    me->equip(ice1);
    me->equip(cure1);
    me->equip(ice2);
    me->equip(cure2);
    // Try to equip fifth Materia (should not crash)
    AMateria *extraMateria = new Ice();
    me->equip(extraMateria);

    // Test using Materias
    me->use(-1, *bob);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    // Test unequipping
    me->unequip(-11);
    me->unequip(2);
    me->use(2, *bob); // This should not crash

    // Test copy constructor
    Character *clone = new Character(*me);
    clone->use(0, *bob);
    clone->use(1, *bob);
    // clone->use(2, *bob);
    clone->use(3, *bob);
    assert(clone->getName() == me->getName());
	
    // Test assignment operator
    Character *anotherCharacter = new Character("Another");
    *anotherCharacter = *me;
    assert(anotherCharacter->getName() == me->getName());

    // Cleanup
    delete me;
	delete extraMateria;
    delete bob;
    delete clone;
    delete anotherCharacter;

    std::cout << "Character Test Passed!\n";
}

// Test Materia Cloning
void testMateriaCloning()
{
    printTestHeader("Materia Cloning Test");

    // Test Ice Materia
    Ice *originalIce = new Ice();
    AMateria *clonedIce = originalIce->clone();

    assert(clonedIce != NULL);
    assert(clonedIce->getType() == "ice");
    assert(clonedIce != originalIce);

    // Test Cure Materia
    Cure *originalCure = new Cure();
    AMateria *clonedCure = originalCure->clone();

    assert(clonedCure != NULL);
    assert(clonedCure->getType() == "cure");
    assert(clonedCure != originalCure);

    // Cleanup
    delete originalIce;
    delete clonedIce;
    delete originalCure;
    delete clonedCure;

    std::cout << "Materia Cloning Test Passed!\n";
}

int main()
{
    try
    {
        testMateriaSource();
		testCharacter();
        testMateriaCloning();

        std::cout << "\n===== ALL TESTS PASSED! =====\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test Failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
