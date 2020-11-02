#include "computor.h"

int     is_math_symb(char c)
{
    if (c == '%' || c == '*' || c == '+' || c == '=' || 
        c == '-' || c == '/' || c == '^')
        return (1);
    return (-1);
}

int     is_parenthesis(char c)
{
    if (c == '(')
        return (1);
    if (c == ')')
        return (-1);
    return (0);
}