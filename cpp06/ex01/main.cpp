#include "Serializer.hpp"

int main(void)
{
	Data		*meow = new Data;
	uintptr_t	holder;

	meow->value = 10;
	holder = Serializer::serialize(meow);
	std::cout << "Meow's address: " << meow << " - holder's value: " << holder << std::endl;
	std::cout << "Deserializing: " << Serializer::deserialize(holder) << ", value inside Data: " << Serializer::deserialize(holder)->value << std::endl;
	delete meow;
	return 0;
}