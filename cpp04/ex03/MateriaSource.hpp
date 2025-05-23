#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*		Srcs[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource();
	void			learnMateria(AMateria* m);
	AMateria*		createMateria(std::string const & type);
};

#endif
