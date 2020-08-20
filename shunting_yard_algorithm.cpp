
#include "shunting_yard_algorithm.h"

std::vector<std::string> shunting_yard_algorithm::parse_to_RPN(std::string infix_expression)
{
	// Shunting-yard algorithm takes an infix expression and produces a postfix expression

	std::vector<std::string> operator_stack;
	std::vector<std::string> output;
	std::string temp_str;


	while (infix_expression.size() > 0)
	{
		// constant (1/2)
		// (temp_str is used to store multiple-digit numbers)
		if (math::is_number(infix_expression.front()) || infix_expression.front() == '.')
		{
			temp_str.push_back(infix_expression.front());
			infix_expression.erase(infix_expression.begin());
			continue;
		}

		// constant (2/2)
		// (when encountering a non-number, push temp_str to output if it is containing values)
		if (!(math::is_number(infix_expression.front())) && temp_str.size() > 0)
		{
			output.push_back(temp_str);
			temp_str.clear();
			// no continue-keyword here because other actions are required
		}

		// variable (x)
		if (infix_expression.front() == 'x')
		{
			output.push_back("x");
			infix_expression.erase(infix_expression.begin());
			continue;
		}

		// operator
		if (math::return_op_precedence(infix_expression.front()))
		{
			if (operator_stack.size() == 0)
			{
				std::string temp_str;
				temp_str.push_back(infix_expression.front());

				operator_stack.push_back(temp_str);
				infix_expression.erase(infix_expression.begin());
				continue;
			}

			if (operator_stack.back() != "^" && infix_expression.front() != '^')
			{
				while (operator_stack.size() > 0 && math::return_op_precedence(operator_stack.back().back()) >= math::return_op_precedence(infix_expression.front()))
				{
					output.push_back(operator_stack.back());
					operator_stack.pop_back();
				}
			}

			std::string temp_str;
			temp_str.push_back(infix_expression.front());

			operator_stack.push_back(temp_str);
			infix_expression.erase(infix_expression.begin());
			continue;
		}

		// '('

		if (infix_expression.front() == '(')
		{
			std::string temp_str;
			temp_str.push_back(infix_expression.front());

			operator_stack.push_back(temp_str);
			infix_expression.erase(infix_expression.begin());
			continue;
		}

		// ')'

		if (infix_expression.front() == ')')
		{
			while (operator_stack.size() > 0 && operator_stack.back() != "(")
			{
				output.push_back(operator_stack.back());
				operator_stack.pop_back();
			}
			if (operator_stack.size() > 0 && operator_stack.back() == "(")
			{
				operator_stack.pop_back();
			}
			infix_expression.erase(infix_expression.begin());
			continue;
		}

		// function

		for (std::string function : math::function_list)
		{
			// If there is an occurance of one of the functions at the front of the expression
			if (infix_expression.find(function) == 0 && infix_expression.find_first_of(function) != std::string::npos)
			{
				std::string temp_str;

				for (unsigned int i = 0; i < function.length(); i++)
				{
					temp_str += infix_expression.front();
					infix_expression.erase(infix_expression.begin());
				}

				operator_stack.push_back(temp_str);
				break;
			}
		}

		continue;
	}

	// if last element in infix expression is a number, push temp_str to output

	if (temp_str.size() > 0)
	{
		output.push_back(temp_str);
		temp_str.clear();
	}

	// if there are still elements in operator stack, pop them to the output

	if (operator_stack.size() > 0)
	{
		while (operator_stack.size() > 0)
		{
			output.push_back(operator_stack.back());
			operator_stack.pop_back();
		}
	}

	return output;
}
