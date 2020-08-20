
#include <math.h>
#include <vector>

#include "math.h"

unsigned int math::return_op_precedence(char& ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '*':
		return 2;
	case '/':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	default:
		return 0;
	}
}

bool math::is_number(char& ch)
{
	// '0' to '9' minus 10 must be smaller than 10 (0 to 9)
	return unsigned int(ch - '0') < 10 ? true : false;
}

bool math::is_number(std::string& str)
{
	// same idea as the function above
	// this handles numbers with multiple digits
	return unsigned int(str.back() - '0') < 10 ? true : false;
}

double math::str_to_int(std::string& str)
{
	// TODO: enable the use of decimals

	// if the string contains a single number ('0' to '9')
	if (str.size() == 1)
	{
		int number = str.back() - '0';
		return static_cast<double>(number);
	}
	
	// if number is not negative
	if (str.front() != '-')
	{
		double output = 0.0;
		unsigned int str_size = str.size();

		for (unsigned int i = 0; i < str_size; i++)
		{
			// iterates through std::string
			// number_ch stores current number (stored as char)
			// number_int converts number_ch from char to int
			char number_ch = str.at((str_size - 1) - i);
			int  number_int = number_ch - '0';

			output += pow(10,i) * (static_cast<double>(number_int));
		}

		return output;
	}

	// if number is negative
	if (str.front() == '-')
	{
		double output = 0.0;
		unsigned int str_size = str.size();

		for (unsigned int i = 0; i < str_size; i++)
		{
			char number_ch = str.at((str_size - 1) - i);
			
			if (number_ch == '-')
			{
				output = -output;
				return output;
			}
			
			int number_int = number_ch - '0';

			output += pow(10, i) * (static_cast<double>(number_int));
		}
	}

	return 0.0;
}

double math::eval(double& operand_one, double& operand_two, char& operatr)
{
	switch (operatr)
	{
	case '^':
		return pow(operand_one, operand_two);
	case '*':
		return operand_one * operand_two;
	case '/':
		return operand_one / operand_two;
	case '+':
		return operand_one + operand_two;
	case '-':
		return operand_one - operand_two;
	default:
		return 0.0;
	}
}

double math::eval(double& operand, std::string& function)
{
	if (function == "sqrt")
	{
		return sqrt(operand);
	}
	else if (function == "sin")
	{
		return sin(operand);
	}
	else if (function == "cos")
	{
		return cos(operand);
	}
	else if (function == "tan")
	{
		return tan(operand);
	}

	return 0.0;
}

double math::eval_postfix_expr(std::vector<std::string> postfix_exp)
{
	std::vector<double> output;
	
	for (std::string element : postfix_exp)
	{
		// number

		if (math::is_number(element))
		{
			double number = std::stod(element);
			output.push_back(number);
		}
		
		// operator

		else
		{
			double operand_two = output.back();
			output.pop_back();

			double operand_one = output.back();
			output.pop_back();

			char operatr = element.front();

			double result = math::eval(operand_one, operand_two, operatr);

			output.push_back(result);
		}
	}

	// if the algorithm is successful, output should only contain one variable

	return output.front();
}

double math::eval_postfix_expr_at(std::vector<std::string> postfix_exp, double& var)
{
	std::vector<double> output;

	for (std::string element : postfix_exp)
	{
		// number

		if (math::is_number(element))
		{
			double number = std::stod(element);
			output.push_back(number);
			continue;
		}

		// variable

		if (element == "x")
		{
			output.push_back(var);
			continue;
		}

		// function

		if (element.size() > 1)
		{
			for (std::string function : math::function_list)
			{
				if (element == function)
				{
					double operand = output.back();
					output.pop_back();

					std::string function = element;

					double result = math::eval(operand, function);
					output.push_back(result);

					break;
				}
			}
			continue;
		}

		// operator

		else
		{
			double operand_two = output.back();
			output.pop_back();

			double operand_one = output.back();
			output.pop_back();

			char operatr = element.front();

			double result = math::eval(operand_one, operand_two, operatr);

			output.push_back(result);
		}
	}

	// if the algorithm is successful, output should only contain one variable

	return output.front();
}
