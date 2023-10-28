#include "lib/New_Parser.h"
#include "lib/Lexer.h"


int main() {

	std::queue<Token> tokens; // holds all standard input
	std::unordered_map<std::string, double> variables; // holds all currently assigned variables
	std::string line;
	New_Parser infix;
		
	while(getline(std::cin, line)) {
		try{
			Lexer lexer;
			lexer.lex(line);
			std::queue<Token> tokenizedQ = lexer.getLexQueue();
			TreeNode* rootTree = infix.parse(tokenizedQ);

			rootTree->printInfix();
			std::cout << std::endl;

			double result = rootTree->evaluateNode(variables);
			std::cout << result << std::endl;
			delete rootTree;
		}
		catch(const std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
	}
};
