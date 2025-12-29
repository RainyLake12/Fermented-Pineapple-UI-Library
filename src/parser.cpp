#include <objects.hpp>
#include <lexer.hpp>
#include <exception>

using std::vector;

FPULObj parseToken(vector<Token> tokens)
{
int index;
FPULObj root;
FPULObj current;
current.parent = nullptr;
while (tokens[index].type != END)
{
    if (tokens[index].type == IDENT)
    {
            if (tokens[index + 1].type == LCURLY)
            {
                FPULObj newCurrentObj;
                newCurrentObj.parent = &current;
                current = newCurrentObj;
                index++;
                continue;
            } else if (tokens[index + 1].type == COLON)
            {
                vector<Token> exprTokens;
                while (tokens[index].type != SEMI)
                {
                    exprTokens.push_back(tokens[index]);
                    index++;
                }
                // TODO : Parse expression after IDENT: expr
            } else
            {
                throw "Unexpected token " + tokens[index + 1].value + " after " + tokens[index].value;
            }
        }
    }
}