#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>

class RPN
{
	private:
		std::string _input;
		std::stack<int> _stack;
		void fill_input_calc();
		bool check_token_valid(std::string token);
		bool check_input_valid();
		void check_stacksize();
	public:
		RPN();
		RPN(std::string input);
		RPN(RPN const &rhs);
		~RPN();
		RPN &operator=(RPN const &rhs);

};

#endif