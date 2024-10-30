// Question Link : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08

// Solution - >

class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(auto ch:s)
        {
            if(ch=='[')
            {
                st.push(ch); //Adding opening brackets in the stack;
            }
            else if(!st.empty()) //To make open brackets balanced with close one;
            {
                st.pop();
            }
        }

        int size = st.size();

        return (size+1)/2;
    }
};