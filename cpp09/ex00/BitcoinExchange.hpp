#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <fstream>
# include <vector>
# include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(std::ifstream &data, std::ifstream &input);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange								&operator=(const BitcoinExchange &other);
	void										printData(void) const;
private:
	std::map<std::string, float>				_data;
	std::vector<std::pair<std::string, float> >	_input;
};

std::map<std::string, float>					parseData(std::ifstream &data);
std::vector<std::pair<std::string, float> >		parseInput(std::ifstream &input);
bool											badFormat(std::string::iterator s);

#endif

