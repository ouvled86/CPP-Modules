#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::vector<int>	vec1;
	for (int i = 0; i < 19997; i++)
		vec1.push_back(i);
	// vec1.push_back(1); // Uncomment to test exception throwing
	Span span1(20000);
	// span1.shortestSpan(); // Uncomment to test exception throwing
	span1.addNumber(2);
	span1.addNumber(100);
	span1.addNumber(5);
	// span1.addNumber(10000); // Uncomment to test exception throwing
	Span span2(span1);
	Span span3(20000);
	span3 = span2;
	span3.addRange(vec1.begin(), vec1.end());
	std::cout << "Shortest Span is: " << span3.shortestSpan() << std::endl;
	std::cout << "Longest Span is: " << span3.longestSpan() << std::endl;
}
