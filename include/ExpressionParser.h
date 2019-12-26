//
// Created by 6rayWa1cher on 26.12.2019.
//

#ifndef HW1SEM3_EXPRESSIONPARSER_H
#define HW1SEM3_EXPRESSIONPARSER_H

#include <string>
#include <Scanner.h>

class ExpressionParser {
private:
	Scanner& scanner;

	bool nodeE();

	bool nodeE7();

	bool nodeE7Dot();

	bool nodeE6();

	bool nodeE6Dot();

	bool nodeE5();

	bool nodeE5Dot();

	bool nodeE4();

	bool nodeE4Dot();

	bool nodeE3();

	bool nodeE3Dot();

	bool nodeE2();

	bool nodeE1();

	bool nodeE1Dot();

	bool nodeE0();

	bool checked = false;
	bool good = false;
public:
	explicit ExpressionParser(Scanner& istream);

	bool checkExpression();
};

#endif //HW1SEM3_EXPRESSIONPARSER_H
