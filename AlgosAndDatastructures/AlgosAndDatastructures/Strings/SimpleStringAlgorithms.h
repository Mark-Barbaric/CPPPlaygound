//
// Created by Mark Barbaric on 28/10/2019.
//

#ifndef BACKTRACKING_SIMPLESTRINGALGORITHMS_H
#define BACKTRACKING_SIMPLESTRINGALGORITHMS_H

#include <string>
#include <stack>

class SimpleStringAlgorithms
{
public:
    SimpleStringAlgorithms() = default;


    bool isValidParenthesis(std::string& s)
    {

        std::stack<char> stack;
        char x;

        for(int i = 0; i < s.length(); ++i)
        {
            auto c = s[i];

            if(c == '(' || c == '[' || c == '{')
                stack.push(c);

            if (stack.empty())
                return false;

            switch(c)
            {
                case ')':
                    x = stack.top();
                    stack.pop();

                    if(x != '(')
                        return false;

                    break;

                case ']':
                    x = stack.top();
                    stack.pop();

                    if(x != '[')
                        return false;

                    break;

                case '}':
                    x = stack.top();
                    stack.pop();

                    if(x != '{')
                        return false;

                    break;

                    default:
                        break;

            }
        }

        return (stack.empty());
    }


};

#endif //BACKTRACKING_SIMPLESTRINGALGORITHMS_H
