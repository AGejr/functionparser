
#include "expression.h"

double expression::eval_at(double& var)
{
	return math::eval_postfix_expr_at(m_postfix_expression, var);
}

std::ostream& operator<<(std::ostream& os, const expression& expr)
{
	const char* char_array = expr.m_infix_expression.c_str();
	os << char_array;
	return os;
}
