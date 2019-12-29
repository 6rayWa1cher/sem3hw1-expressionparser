#include <iostream>
#include <sstream>
#include "Scanner.h"
#include "../include/ExpressionParser.h"

int main() {
	std::string input = "1 + 2";
	std::cout << "Type expression (or garbage)" << std::endl;
	std::getline(std::cin, input);
	std::cout << "Got " << input << std::endl;
	try {
		std::istringstream iss(input);
		Scanner scanner(iss);
		ExpressionParser expParser(scanner);
		if (expParser.checkExpression()) {
			std::cout << "It's an expression! ^_^" << std::endl;
		} else {
			std::cout << "Garbage >:(" << std::endl;
		}
	} catch (std::ios_base::failure& e) {
		std::cout << "Something went wrong" << std::endl;
	}
	return 0;
}