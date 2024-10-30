// Question Link : https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28

// Solution : 

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        unordered_map<int,int>mp;

        int maxStreak = 0;

        for(int &num:nums){
            int root = (int)sqrt(num);

            if(root*root == num && mp.find(root)!=mp.end()){
                mp[num]=mp[root]+1;
            }
            else{
                mp[num]=1;
            }
            maxStreak = max(maxStreak,mp[num]);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};