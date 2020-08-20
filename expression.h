
#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "shunting_yard_algorithm.h"

class expression
{
public:

	// Constructors

	expression(const char* char_array)
	{
		std::string expr(char_array);

		m_infix_expression = expr;
		m_postfix_expression = shunting_yard_algorithm::parse_to_RPN(expr);
	}

	// Member functions

	double eval_at(double& var);

	friend std::ostream& operator<<(std::ostream& os, const expression& expr);

private:

	// Member variables

	std::string m_infix_expression;
	std::vector<std::string> m_postfix_expression;


};

