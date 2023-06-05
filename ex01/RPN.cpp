
#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &rhs)
{
	*this = rhs;
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_input = rhs._input;
		_stack = rhs._stack;
	}
	return *this;
}

bool RPN::check_input_valid()
{
	
	std::string validchars = "0123456789+-*/% ";
	return (_input.find_first_not_of(validchars) == std::string::npos);
}

RPN::RPN(std::string input)
{
	_input = input;
	if (!check_input_valid())
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	fill_input_calc();
}

bool RPN::check_token_valid(std::string token)
{
	if(token.length() == 1)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
			return true;
	}
	else if (token.length() == 2)
	{
		if (token[0] != '-' && token[0] != '+')
			return false;
		if (isdigit(token[1]) == false)
			return false;
	}
	return true;
}

void RPN::fill_input_calc()
{
	std::stringstream ss(_input);
	std::string token;
	int i;
	while(getline(ss, token, ' '))
	{
		if (check_token_valid(token) == false)
		{
			std::cout << "Invalid token: " << token << std::endl;
			exit(1);
		}
		if (token.length() == 2 || isdigit(token[0]))
			_stack.push(atoi(token.c_str()));
		else if (token == "+")
		{
			i = _stack.top();
			_stack.pop();
			i += _stack.top();
			_stack.pop();
			_stack.push(i);
		}
		else if (token == "-")
		{
			i = _stack.top();
			_stack.pop();
			i = _stack.top() - i;
			_stack.pop();
			_stack.push(i);
		}
		else if (token == "*")
		{
			i = _stack.top();
			_stack.pop();
			i *= _stack.top();
			_stack.pop();
			_stack.push(i);
		}
		else if (token == "/")
		{
			i = _stack.top();
			_stack.pop();
			i = _stack.top() / i;
			_stack.pop();
			_stack.push(i);
		}
		else if (token == "%")
		{
			i = _stack.top();
			_stack.pop();
			i = _stack.top() % i;
			_stack.pop();
			_stack.push(i);
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	std::cout << _stack.top() << std::endl;
}
