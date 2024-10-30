// Question Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09

// Solution ->


class Solution {
public:

    int SameMethod1(string s)
    {
        int open=0;
        int size=0;

        for(auto ch:s)
        {
            if(ch=='(')
            {
                size++; //Pushed '(' in the stack therefore size of the stack increases
            }
            else if(size>0)
            {
                // means ')' comes up
                size--; //decreasing bcoz we know '(' would be there in the stack and to make valid we pop it out of the stack;
            }
            else
            {
                open++; //It will add one more open bracket to make the string valid;
            }
        }

        return open+size;
    }



    int SameMethod2(string s)
    {
        int openBracket=0;
        int closeBracket=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                openBracket++;
            }
            else
            {
                if(openBracket>0)
                {
                    openBracket--;
                }
                else
                {
                    closeBracket++;
                }
            }
        }

        return openBracket+closeBracket;
    }

    int minAddToMakeValid(string s) {
        int ans = SameMethod1(s);


        return ans;
    }
};