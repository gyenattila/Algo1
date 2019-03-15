#include "Stack.hpp"

bool isOperandus(char);
bool isOperator(char);
bool isLeftToRightOperator(char);
int operatorPrecendency(char);
void lengyelForma(const std::string&);

int main()
{
    std::string s;
    std::cin >> s;
    lengyelForma(s);
    return 0;
}

bool isOperandus(char c) { return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')); }
bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '='); }
bool isLeftToRightOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

int operatorPrecendency(char o)
{
    if(o == '=')
        return 1;
    else if(o == '+' || o == '-')
        return 2;
    else if(o == '*' || o == '/')
        return 3;
    else if(o == '^')
        return 4;
    return -1;
}

void lengyelForma(const std::string& str)
{
    Stack v(str.length());

    for(int i = 0; i < str.length(); ++i)
    {
        char x = str[i];

        if(isOperandus(x))
            std::cout << x;
        else if(x == '(')
            v.push(x);
        else if(x == ')')
        {
            while(v.top() != '(')
                std::cout << v.pop();
            v.pop();
        }
        else if(isOperator(x))
        {
            if(isLeftToRightOperator(x))
            {
                while(!v.isEmpty() && v.top() != '(' && operatorPrecendency(x) <= operatorPrecendency(v.top()))
                    std::cout << v.pop();
                v.push(x);
            }
            else
            {
                while(!v.isEmpty() && v.top() != '(' && operatorPrecendency(x) < operatorPrecendency(v.top()))
                    std::cout << v.pop();
                v.push(x);
            }
        }
    }

    while(!v.isEmpty())
        std::cout << v.pop();
}
