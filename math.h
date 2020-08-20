
#pragma once

#include <string>

namespace math
{
	unsigned int return_op_precedence(char& ch);

	bool is_number(char& ch);
	bool is_number(std::string& str);
		
	double str_to_int(std::string& str);

	double eval(double& operand_one, double& operand_two, char& operatr);
	double eval(double& operand, std::string& function);

	double eval_postfix_expr(std::vector<std::string> postfix_exp);

	double eval_postfix_expr_at(std::vector<std::string> postfix_exp, double& var);

	const std::vector<std::string> function_list{ "sqrt", "sin", "tan", "cos" };
}