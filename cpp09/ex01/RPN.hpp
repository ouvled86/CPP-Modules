#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <stack>

class RPN
{
public:
	RPN(void);
	RPN(std::string &expr);
	RPN(const RPN& other);
	~RPN();
	RPN					&operator=(const RPN &other);
	void				evaluate(void);
	void				printResult(void) const;
private:
	std::string			_expr;
	std::stack<double>	_ctr;
	double				_result;
	bool				_errFlag;
};

bool					badInput(std::string &input);
double					calculate(double oprd1, double oprd2, char oprt);

#endif
