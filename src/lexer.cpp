#include <string>
#include <objects.hpp>
#include <sstream>
#include <lexer.hpp>

using std::string, std::vector, std::stringstream;

TokenTypes getTokenByChar(char token)
{
    if (token == '+') return PLUS;
    if (token == '-') return MINUS;
    if (token == '*') return STAR;
    if (token == '/') return SLASH;
    if (token == '(') return LPAREN;
    if (token == ')') return RPAREN;
    if (token == '{') return LCURLY;
    if (token == '}') return RCURLY;
    if (token == ';') return SEMI;
    if (token == ':') return COLON;
    if (token == '#') return HASH;

    return SEMI;
}

vector<Token> lex(string text)
{
    string opChars = "+-*/=;(){}:#";
    vector<string> operators = {};
    vector<Token> tokens;
    stringstream stream(text);
    string buffer;
    int ch;
    while ((ch = stream.get()) != EOF)
    {
        if (isspace(ch) || iscntrl(ch))
        {
            continue;
        } else if (isdigit(ch))
        {
            buffer += ch;
            while (isalnum(stream.peek()))
            {
                buffer += stream.get();
            }

            Token token;
            token.type = NUM;
            token.value = buffer;
            buffer = "";
            tokens.push_back(token);
            continue;
        } else if (isalpha(ch))
        {
            buffer += ch;
            while (isalnum(stream.peek()))
            {
                buffer += stream.get();
            }

            Token token;
            token.type = IDENT;
            token.value = buffer;
            buffer = "";
            tokens.push_back(token);
            continue;
        } else
        {
            if (ch == ';')
            {
                Token token;
                token.type = SEMI;
                tokens.push_back(token);
                continue;
            } else if (opChars.find(ch) != string::npos)
            {
                Token token;
                token.type = getTokenByChar(ch);
                tokens.push_back(token);
                continue;
            }
        }
    }

    return tokens;
}