#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
private:
	std::string			ideas[100];
	int					size;

public:
	Brain(void);
	Brain(const Brain& other);
	Brain				&operator=(const Brain &other);
	~Brain();
	void				addIdea(const std::string& idea);
	const std::string&	getIdea(int index) const;
	const int&			getSize() const;
};

#endif
