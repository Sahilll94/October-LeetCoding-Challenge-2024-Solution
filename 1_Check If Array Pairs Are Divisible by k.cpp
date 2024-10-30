// Question link : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

// Solution -> 

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        //Map
        vector<int>mp(k,0);

        // 1 STEP FROM ALGO;
        // find remainder of each element of the "arr";
        for(int num : arr)
        {
            // int rem =  num%k;
            int rem =  (num%k + k) % k; //for the negative elements
            // adding count of remainder in the Map;
            mp[rem]++;
        }

        // for edge cases as even counts should be there;
        if(mp[0]%2!=0)
        {
            return false;
        }

            // 2 STEP FROM ALGO ;
            for(int rem = 1; rem <= k/2; rem++)
            {
                int counterHalf = k - rem;
                if(mp[counterHalf]!=mp[rem])
                {
                    return false;
                }
            }
        

        return true;
    }
};