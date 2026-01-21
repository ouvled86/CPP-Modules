#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>

static bool	isPrintableChar(int v)
{
	return v >= 32 && v <= 126;
}

static bool	isSingleNonDigitChar(const std::string &s)
{
	return s.size() == 1 && (s[0] < '0' || s[0] > '9');
}

static bool	isPseudoDouble(const std::string &s)
{
	return s == "nan" || s == "+inf" || s == "-inf" || s == "inf";
}

static bool	isPseudoFloat(const std::string &s)
{
	return s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
}

static bool	hasFrac(double d)
{
	double ip;
	return std::modf(d, &ip) != 0.0;
}

struct	Parsed
{
	bool	ok;
	double	d;
};

static Parsed	parseNumber(const std::string &s)
{
	Parsed	p;

	p.ok = false;
	p.d = 0.0;

	if (s.empty())
		return p;

	if (isSingleNonDigitChar(s))
	{
		p.ok = true;
		p.d = static_cast<unsigned char>(s[0]);
		return p;
	}

	if (isPseudoFloat(s))
	{
		p.ok = true;
		if (s[0] == '-')
			p.d = -INFINITY;
		else if (s[0] == '+')
			p.d = INFINITY;
		else if (s == "nanf")
			p.d = NAN;
		else if (s == "inff")
			p.d = INFINITY;
		return p;
	}

	if (isPseudoDouble(s))
	{
		p.ok = true;
		if (s[0] == '-')
			p.d = -INFINITY;
		else if (s[0] == '+')
			p.d = INFINITY;
		else if (s == "nan")
			p.d = NAN;
		else if (s == "inf")
			p.d = INFINITY;
		return p;
	}

	char		*end = 0;
	const char	*c = s.c_str();
	double		d = std::strtod(c, &end);

	if (end == c)
		return p;

	if (*end == '\0')
	{
		p.ok = true;
		p.d = d;
		return p;
	}

	if (*end == 'f' && *(end + 1) == '\0')
	{
		p.ok = true;
		p.d = d;
		return p;
	}

	return p;
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static void	printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "impossible\n";
		return;
	}
	int	v = static_cast<int>(d);
	if (v < 0 || v > 127)
	{
		std::cout << "impossible\n";
		return;
	}
	if (!isPrintableChar(v))
	{
		std::cout << "Non displayable\n";
		return;
	}
	std::cout << "'" << static_cast<char>(v) << "'\n";
}

static void	printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) ||
		d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
	{
		std::cout << "impossible\n";
		return;
	}
	std::cout << static_cast<int>(d) << "\n";
}

static void	printFloat(double d, bool integral)
{
	std::cout << "float: ";
	if (std::isnan(d))
	{
		std::cout << "nanf\n";
		return;
	}
	if (std::isinf(d))
	{
		if (d < 0)
			std::cout << "-inff\n";
		else
			std::cout << "+inff\n";
		return;
	}
	float	f = static_cast<float>(d);
	if (integral)
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
		std::cout.unsetf(std::ios::fixed);
	}
	else
		std::cout << f << "f\n";
}

static void	printDouble(double d, bool integral)
{
	std::cout << "double: ";
	if (std::isnan(d))
	{
		std::cout << "nan\n";
		return;
	}
	if (std::isinf(d))
	{
		if (std::isinf(d))
		{
			if (d < 0)
				std::cout << "-inf\n";
			else
				std::cout << "+inf\n";
			return;
		}
		return;
	}
	if (integral)
	{
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
		std::cout.unsetf(std::ios::fixed);
	}
	else
		std::cout << d << "\n";
}

void	ScalarConverter::convert(const char *input)
{
	std::string	s;
	if (!input)
		s = "";
	else
		s = input;
	Parsed	p = parseNumber(s);

	if (!p.ok)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	double	d = p.d;
	bool	integral = !std::isnan(d) && !std::isinf(d) && !hasFrac(d);

	printChar(d);
	printInt(d);
	printFloat(d, integral);
	printDouble(d, integral);
}
