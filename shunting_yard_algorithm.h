
#pragma once

#include <Windows.h>
#include <vector>
#include <string>

#include "math.h"

namespace shunting_yard_algorithm
{
	std::vector<std::string> parse_to_RPN(std::string infix_expression);
}