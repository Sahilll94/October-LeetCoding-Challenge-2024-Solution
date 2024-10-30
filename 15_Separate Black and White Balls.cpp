// Question Link : https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

// Solution -> 

class Solution {
public:
    long long minimumSteps(string s) {
        int black = 0; //black = 1;

        long long swap = 0;

        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                black++;
            }
            else
            {
               swap+=black; 
            }
        }

        return swap;
    }
};