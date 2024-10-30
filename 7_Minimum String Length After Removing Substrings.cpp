// Question Link : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07

// Solution -> 


class Solution {
public:
    int minLength(string s) {
        string temp;

        int n= s.size();
        char ch;


        for(auto ch : s)
        {
            if(!temp.empty() && ch =='B' && temp.back()=='A')
            {
                temp.pop_back();
            }
            else if(!temp.empty() && ch =='D' && temp.back()=='C')
            {
                temp.pop_back();
            }
            else
            {
                temp+=ch;
            }
        }

        return temp.size();
    }
};
