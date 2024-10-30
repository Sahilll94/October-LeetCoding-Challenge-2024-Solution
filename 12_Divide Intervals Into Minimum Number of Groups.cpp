// Question Link : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

// Solution ->

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sort the intervals;
        sort(intervals.begin(),intervals.end());

        // used a priority queue;
        priority_queue<int,vector<int>,greater<int>>group;

        for(vector<int>&interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];

            // If upcoming's start is greater then we can create a group or we can merge it then there's no need of the group;
            if(!group.empty() && start>group.top())
            {
                group.pop();
            }

            // if not then create a new group;
            group.push(end);
        }

        return group.size();
    }
};