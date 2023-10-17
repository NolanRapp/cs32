#include "lib/Parser.h"
#include "lib/Lexer.h"


int main() {

	char tempChar;
	std::string totalString = "\0";
	while(std::cin.get(tempChar)){
		totalString += tempChar;
	}
	
	std::queue<Token> tokens;

	// Creates queue by reading user input
	Lexer lexer;
	lexer.lex(totalString);
	Parser parser(lexer.getLexQueue());

	// Retrieves tree and evaluates
	TreeNode* ASThead = parser.getHead();
	ASThead->printInfix();
	std::cout << std::endl;

	try {
		double calculation = ASThead->evaluateNode();
		delete ASThead;
		std::cout << calculation << std::endl;
	}

	catch (const std::runtime_error& e) {
		delete ASThead;
		std::cout << e.what() << std::endl;
		return 3;
	}

   return 0;
};

