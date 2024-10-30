// Question Link : https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10

// Solution -> 

class Solution {
public:

    int bruteForce(vector<int>&nums)
    {
        int ans=0;

        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<=nums[j])
                {
                    ans=max(ans,j-i);
                }
            }
        }

        

        return ans;
    }


    int Sorting(vector<int>&nums)
    {
        int ans = 0;
        int n = nums.size();

        vector<pair<int, int>> vp;
        // storing element with their index
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        // Keep track of the minimum index seen so far
        int minIndex = vp[0].second;

        for (int i = 1; i < n; i++) {
            // Calculate the width and update the maximum ramp width
            ans = max(ans, vp[i].second - minIndex);
            // Update the minimum index
            minIndex = min(minIndex, vp[i].second);
        }

        return ans;

    }

    int TwoPointer(vector<int>&nums)
    {
        int n=nums.size();

        vector<int>rightMax(n);

        // store last element as it is from nums to rightMax as we are going to find max from the right;
        rightMax[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            // Here, We are comparing nums and rightMax and finding the max from right;
            rightMax[i]=max(nums[i],rightMax[i+1]);
        }

        int ramp=0;
        int i=0; //For pointing at nums'
        int j=0; //For pointing at rightMax;

        while(j<n)
        {
            // shifting i to +1 if nums[i]<=nums[j] condition fails;
            while(i<j && nums[i]>rightMax[j])
            {
                i++;
            }

            ramp=max(ramp,j-i);
            j++;
        }

        return ramp;
    }

    int maxWidthRamp(vector<int>& nums) {
        // int ans = bruteForce(nums);
        // int ans = Sorting(nums);
        int ans = TwoPointer(nums);


        return ans;
    }
};  