#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>

class FragTrap
{
    public:
        FragTrap(void);
        FragTrap(const FragTrap& other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();
};

#endif

