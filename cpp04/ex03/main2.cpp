#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>
#include <cassert>
int main()
{
    try
    {
        // testMateriaSource();
        // testCharacter();
        // testMateriaCloning();
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        Character* me = new Character("me");

        AMateria    *ice = src->createMateria("ice");
        me->equip(ice);
        me->unequip(0);
        delete ice;

        AMateria* tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        Character* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob);

        Character *clone = new Character(*me);
        (void)clone;

        return 0;

        std::cout << "\n===== ALL TESTS PASSED! =====\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test Failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}