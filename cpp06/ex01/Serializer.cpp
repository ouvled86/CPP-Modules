#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	(void) other;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	(void) other;
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);

	return (ret);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data	*retptr = reinterpret_cast<Data *>(raw);

	return (retptr);
}

