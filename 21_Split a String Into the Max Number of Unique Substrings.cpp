// Question Link : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21

// Solution -> 

class Solution {
public: 
    void solve(int index, unordered_set<string>&st,string s, int &count)
    {
        if(index==s.size())
        {
            int setSize = st.size();
            count = max(setSize,count);
        }

        string str = "";
        for(int i=index;i<s.size();i++)
        {
            str.push_back(s[i]);
            if(st.contains(str))
            {
                continue;
            }
            else
            {
                st.insert(str);
                solve(i+1,st,s,count);
                st.erase(str);
            }
        }
    }


    int maxUniqueSplit(string s) {
        unordered_set<string>st;

        int n = s.size();

        int count = 0;

        solve(0,st,s,count);


        return count;
    }
};