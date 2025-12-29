#include <string>
#include <vector>

enum TokenTypes
{
    LPAREN, RPAREN, COLON, LCURLY, RCURLY, IDENT, NUM, STRING,
    PLUS, MINUS, STAR, SLASH, EQUAL, SEMI, END, HASH
};

struct Token
{
    TokenTypes type;
    std::string value;
};

std::vector<Token> lex(std::string text);