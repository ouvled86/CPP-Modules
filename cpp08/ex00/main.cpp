#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int>	vec;
	std::list<int>		li;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	li.push_back(6);
	li.push_back(7);
	li.push_back(8);
	li.push_back(9);
	li.push_back(0);

	std::cout << "easyfind(li, 1): " << easyfind(li, 1) << std::endl;
	std::cout << "easyfind(vec, 6): " << easyfind(vec, 6) << std::endl;

	std::cout << "easyfind(li, 0): " << easyfind(li, 0) << std::endl;
	std::cout << "easyfind(vec, 2): " << easyfind(vec, 2) << std::endl;
}