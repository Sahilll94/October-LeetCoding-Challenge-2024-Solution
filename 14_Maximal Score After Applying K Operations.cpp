// Question Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14

// Solution -> 

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;

        int n = nums.size();

        for(int num : nums)
        {
            maxHeap.push(num);
        }

        long long int score = 0;

        for(int i=0;i<k;i++)
        {
            int maxValue = maxHeap.top();
            maxHeap.pop();
            score += maxValue;
            maxValue = ceil((maxValue+2)/3);
            maxHeap.push(maxValue);
        }

        return score;
    }
};