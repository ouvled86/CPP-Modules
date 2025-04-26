#include <iostream>
#include <cmath>

float simpleSqrt(double n) {
    double guess = 1.0;
    while (guess * guess <= n) {
        guess += 0.01;
    }
    return guess - 0.01;
}

int main()
{
    double a = 16;
    a = roundf(simpleSqrt(10000000000));
    std::cout << a << '\n';
}