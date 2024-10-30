// Question Link : https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17

// Solution ->

class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        int size  = ans.size();

        priority_queue<pair<char,int>>Heap;

        for(int i=0;i<size;i++)
        {
            Heap.push({ans[i],i});
        }


        for(int i=0;i<size;i++)
        {
            // we are checking on the right side of the num not on the left that's why 
            while(!Heap.empty() && Heap.top().second<i) //If the index is smaller, that means the digit in the priority queue is to the left of the current position j, which means swapping it wouldn’t make sense, as you can only swap with digits to the right of j.
            {
                Heap.pop();
            }

            if(Heap.top().first>ans[i])
            {
                swap(ans[i],ans[Heap.top().second]);
                break;
            }
        }

        return stoi(ans);
    }
};