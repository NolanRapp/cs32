#ifndef NEW_PARSER_H
#define NEW_PARSER_H

#include "Lexer.h"
#include "Token.h"
#include "AST.h"
#include "Errors.h"

#include <deque>
#include <memory>

/* New_Parser implements Recursive Descent Parsing - a top down AST parsing method
        sources: https://en.wikipedia.org/wiki/Recursive_descent_parser
                https://www.youtube.com/watch?v=SToUyjAsaFk
                
*/

class New_Parser {
    /* 
    Parser implentation for infix expressions.
    Each helper function is for a different operator precendence expression
    */

    public:
        New_Parser();
        ~New_Parser();
        
        TreeNode* parse(std::deque<Token>& tokenizedQ); // begins parse, and identifies when to end parse
        TreeNode* parseForCalc(std::deque<Token>& tokenizedQ); // main parse for calc.cpp
        TreeNode* parseForState(std::deque<Token>& tokenizedQ); // main parse for scrypt.cpp

        TreeNode* parseE(std::deque<Token>& tokenizedQ); // parsing and expression
        TreeNode* parseT(std::deque<Token>& tokenizedQ); // parsing a term
        TreeNode* parseF(std::deque<Token>& tokenizedQ); // parsing a factor
        TreeNode* parseA(std::deque<Token>& tokenizedQ); // parsing an assignment tree
        TreeNode* parseAbool(std::deque<Token>& tokenizedQ, std::unique_ptr<TreeIdentifier>& id);
        TreeNode* parseComparison(std::deque<Token>& tokenizedQ); // parsing a comparison operator like "<" or ">="
        TreeNode* parseEquality(std::deque<Token>& tokenizedQ); // parsing an equality statement like "=="
        TreeNode* parseInclusive(std::deque<Token>& tokenizedQ); // parsing logical operations like "&", "^", "|" 
        TreeNode* parseExclusive(std::deque<Token>& tokenizedQ); // parsing logical operations like "&", "^", "|" 
        TreeNode* parseAnd(std::deque<Token>& tokenizedQ); // parsing logical operations like "&", "^", "|" 


    private:
        std::string nextToken; // this is, at any point, the next unscanned token from the Token deque.
        std::string lookahead; // this is, at any point, the token ahead of nextToken
        Type lookaheadType;
        Type tokenType;

        void scanToken(std::deque<Token>& tokenizedQ); // sets nextToken to point to the newly scanned token
        //void throw ParseError(int line, int col, std::string text) const;

        int currentLine;
        int currentColumn;

        std::unordered_map<std::string, double> variables;
};

#endif
