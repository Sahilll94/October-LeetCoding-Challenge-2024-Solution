// Question Link : https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20

// Solution -> 

class Solution {
public:

    void ampersend(stack<char>&expressions, stack<char>&operators)
    {
                    bool flag = true;
                    while(expressions.top()!= '(')
                    {
                        char ch = expressions.top();
                        expressions.pop();

                        if(ch=='f')
                        {
                            flag = false;
                        }
                    }
                    expressions.pop();

                    if(flag)
                    {
                        expressions.push('t');
                    }
                    else
                    {
                        expressions.push('f');
                    }

    }

    void Or(stack<char>&expressions, stack<char>&operators)
    {
        bool flag = false;
        while( expressions.top()!='(')
        {
            char ch = expressions.top();
            expressions.pop();

            if(ch=='t')
            {
                flag=true;
            }
        }
        expressions.pop();

        if(flag)
        {
            expressions.push('t');
        }
        else
        {
            expressions.push('f');
        }
    }

    void Not(stack<char>&expressions,stack<char>&operators)
    {
        char ch = expressions.top();
        expressions.pop();
        expressions.pop();

        if(ch=='t')
        {
            expressions.push('f');
        }
        else
        {
            expressions.push('t');
        }

    }

    bool parseBoolExpr(string s) {
        int n = s.size();

        stack<char>operators;
        stack<char>expressions;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='&' || s[i]=='|' || s[i]=='!')
            {
                operators.push(s[i]);
            }
            else if(s[i]=='t' || s[i]=='f' || s[i]==',' || s[i]=='(')
            {
                expressions.push(s[i]);
            }
            else if(s[i]==')')
            {
                char op = operators.top();
                operators.pop();

                if(op=='&')
                {
                   ampersend(expressions,operators);
                }
                else if(op=='|')
                {
                    Or(expressions,operators);
                }
                else if(op=='!')
                {
                    Not(expressions,operators);
                }
            }
        }

        return expressions.top()=='t' ? true : false;
    }
};