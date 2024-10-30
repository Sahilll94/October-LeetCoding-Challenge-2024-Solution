// Question Link : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18

// Solution -> 


class Solution {
public:

    int Recursion(int index, int currOR, int maxOR, vector<int>nums)
    {
        // Base Case
        if(index==nums.size())
        {
            if(currOR == maxOR)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int take = Recursion (index+1, currOR | nums[index], maxOR, nums);

        int notTake = Recursion (index+1, currOR, maxOR, nums);

        return take+notTake;

    }
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOR = 0;
        
        for(int num : nums)
        {
            maxOR |= num;
        }

        int currOR = 0;

        return Recursion(0,currOR,maxOR, nums);
    }
};