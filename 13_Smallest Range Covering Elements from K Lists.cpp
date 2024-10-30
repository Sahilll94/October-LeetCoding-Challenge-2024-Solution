// Question Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=daily-question&envId=2024-10-13

// Solution -> 

class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        // creating a vector to store the pointer from each list inside the nums vector 
        // and iterate over them to find the maximum and minimum and then find diff 
        // and return it if it has the minimum difference;
        vector<int> vec(k, 0); // 0 as pointing at 0th index of each list inside the nums;
        
        vector<int> Range = {-1000000, 1000000}; // (min, max);

        while (true) {
            int minElement = INT_MAX;
            int minElementIndex = 0; 
            int maxElement = INT_MIN;

            for (int i = 0; i < k; i++) {
                int listIndex = i;
                int elementIndex = vec[i];
                int element = nums[listIndex][elementIndex];

                if (element < minElement) {
                    minElement = element;
                    minElementIndex = listIndex;
                }

                if (element > maxElement) {
                    maxElement = element;
                }
            }

            // range; //FINDING RANGE AND COMPARING IT AND UPDATING;
            if (maxElement - minElement < Range[1] - Range[0]) {
                Range[0] = minElement;
                Range[1] = maxElement;
            }

            // move minElement's ith pointer to the next;
            int nextIndex = vec[minElementIndex] + 1;
            // OUT OF BOUND CONDITION OVER A LIST;
            if (nextIndex >= nums[minElementIndex].size()) {
                break; //Terminate if nextIndex goes out of bound for one list;
            }
            vec[minElementIndex] = nextIndex;
        }

        return Range;
    }
};
