
#include <iostream>

#include "shunting_yard_algorithm.h"
#include "math.h"
#include "expression.h"

int main()
{
	/*
	std::string infix_expression = "3+4*2/(1-5)^2^3";

	std::cout << "Infix expression: " << infix_expression << "\n";

	std::string postfix_expression = shunting_yard_algorithm::parse(infix_expression);

	std::cout << "Postfix expression: " << postfix_expression << "\n";
	*/

	/*

	std::string str = "42356";

	std::cout << "str: " << str << " // int: " << math::str_to_int(str) << "\n";

	*/

	/*

	std::string infix_expression = "11+4*2/(1-5)^2^3";

	std::cout << "Infix expression: " << infix_expression << "\n";

	std::vector<std::string> postfix_expression = shunting_yard_algorithm::parse(infix_expression);

	std::cout << "Postfix expression: ";
	for (std::string element : postfix_expression)
	{
		std::cout << element;
	}
	std::cout << "\n";
	
	*/

	/*

	std::string infix_expression = "(3+((7-1)*2^2))^2";

	std::cout << "Infix expression: " << infix_expression << "\n";

	std::vector<std::string> postfix_expression = shunting_yard_algorithm::parse_to_RPN(infix_expression);

	std::cout << "Postfix expression: ";
	for (std::string element : postfix_expression)
	{
		std::cout << element;
	}
	std::cout << "\n";

	std::cout << "Evaluation of postfix expression: " << math::eval_postfix_expr(postfix_expression) << "\n";
	
	*/

	/*

	expression expr("3.5*2^(2+0.65)");
	double result = expr.eval();

	std::cout << expr << " = " << result << "\n";

	std::string result_str = std::to_string(result);

	std::cout << "Result as a string: " << result_str << "\n";

	*/

	/*std::string str = "sqrt";
	double operand = 1.0;
	double db = math::eval(operand, str);*/

	expression expr("tan(2^2)");
	
	for (double i = 0; i < 100; i += 0.1)
	{
		double result = expr.eval_at(i);
		std::cout << expr << " at " << i << " = " << result << "\n";

	}

	return 0;
}
