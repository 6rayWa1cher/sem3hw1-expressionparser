//
// Created by 6rayWa1cher on 26.12.2019.
//

#include "../include/ExpressionParser.h"
#include <string>
#include <iostream>
#include <sstream>

bool ExpressionParser::checkExpression() {
	if (!checked) {
		good = nodeE();
		checked = true;
	}
	return good;
}

bool ExpressionParser::nodeE() {
	return nodeE7();
}

bool ExpressionParser::nodeE7() {
	if (!nodeE6()) {
		return false;
	}
	if (!nodeE7Dot()) {
		return false;
	}
	return true;
}

bool ExpressionParser::nodeE7Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opor) {
		if (!nodeE6()) return false;
		if (!nodeE7Dot()) return false;
		return true;
	}
	if (token.type() == LexemType::rpar || token.type() == LexemType::eof) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE6() {
	if (!nodeE5()) return false;
	if (!nodeE6Dot()) return false;
	return true;
}

bool ExpressionParser::nodeE6Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opand) {
		if (!nodeE5()) return false;
		if (!nodeE6Dot()) return false;
		return true;
	}
	if (
			token.type() == LexemType::opor ||
			token.type() == LexemType::rpar ||
			token.type() == LexemType::eof
			) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE5() {
	if (!nodeE4()) return false;
	if (!nodeE5Dot()) return false;
	return true;
}

bool ExpressionParser::nodeE5Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opeq) {
		if (!nodeE4()) return false;
		return true;
	}
	if (token.type() == LexemType::opne) {
		if (!nodeE4()) return false;
		return true;
	}
	if (token.type() == LexemType::opgt) {
		if (!nodeE4()) return false;
		return true;
	}
	if (token.type() == LexemType::oplt) {
		if (!nodeE4()) return false;
		return true;
	}
	if (token.type() == LexemType::ople) {
		if (!nodeE4()) return false;
		return true;
	}
	if (
			token.type() == LexemType::opand ||
			token.type() == LexemType::opor ||
			token.type() == LexemType::rpar ||
			token.type() == LexemType::eof
			) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE4() {
	if (!nodeE3()) return false;
	if (!nodeE4Dot()) return false;
	return true;
}

bool ExpressionParser::nodeE4Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opplus) {
		if (!nodeE3()) return false;
		if (!nodeE4Dot()) return false;
		return true;
	}
	if (token.type() == LexemType::opminus) {
		if (!nodeE3()) return false;
		if (!nodeE4Dot()) return false;
		return true;
	}
	if (
			token.type() == LexemType::opeq ||
			token.type() == LexemType::opne ||
			token.type() == LexemType::oplt ||
			token.type() == LexemType::opgt ||
			token.type() == LexemType::ople ||
			token.type() == LexemType::opand ||
			token.type() == LexemType::opor ||
			token.type() == LexemType::rpar ||
			token.type() == LexemType::eof
			) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE3() {
	if (!nodeE2()) return false;
	if (!nodeE3Dot()) return false;
	return true;
}

bool ExpressionParser::nodeE3Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opmult) {
		if (!nodeE2()) return false;
		if (!nodeE3Dot()) return false;
		return true;
	}
	if (
			token.type() == LexemType::opplus ||
			token.type() == LexemType::opminus ||
			token.type() == LexemType::opeq ||
			token.type() == LexemType::opne ||
			token.type() == LexemType::oplt ||
			token.type() == LexemType::opgt ||
			token.type() == LexemType::ople ||
			token.type() == LexemType::opand ||
			token.type() == LexemType::opor ||
			token.type() == LexemType::rpar ||
			token.type() == LexemType::eof
			) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE2() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opnot) {
		if (!nodeE2()) return false;
		return true;
	}
	scanner.pushBack(token);
	if (nodeE1()) {
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE1() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opinc) {
		if (!nodeE0()) return false;
		return true;
	}
	scanner.pushBack(token);
	if (nodeE0()) {
		if (!nodeE1Dot()) return false;
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE1Dot() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::opinc) {
		return true;
	}
	if (
			token.type() == LexemType::opmult ||
			token.type() == LexemType::opplus ||
			token.type() == LexemType::opminus ||
			token.type() == LexemType::opeq ||
			token.type() == LexemType::opne ||
			token.type() == LexemType::oplt ||
			token.type() == LexemType::opgt ||
			token.type() == LexemType::ople ||
			token.type() == LexemType::opand ||
			token.type() == LexemType::opor ||
			token.type() == LexemType::rpar ||
			token.type() == LexemType::eof
			) {
		scanner.pushBack(token);
		return true;
	}
	return false;
}

bool ExpressionParser::nodeE0() {
	Token token = scanner.getNextToken();
	if (token.type() == LexemType::num) {
		return true;
	}
	if (token.type() == LexemType::lpar) {
		if (!nodeE()) return false;
		if (scanner.getNextToken().type() != LexemType::rpar) return false;
		return true;
	}
	return false;
}

ExpressionParser::ExpressionParser(Scanner& scanner) : scanner(scanner) {

}