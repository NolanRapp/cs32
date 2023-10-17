#include "lib/Lexer.h"
#include "lib/Token.h"


int main() {

	char inChar;
	std::string totalString = "\0";
	while(std::cin.get(inChar)){
		totalString += inChar;
	}

    Lexer lexer;
    lexer.lex(totalString);
    lexer.printTokens();

    return 0;
}
