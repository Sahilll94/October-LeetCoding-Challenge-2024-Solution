// Question Link : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11

// Solution ->

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairs(n, -1);

        int targetFriendArrival = times[targetFriend][0];

        sort(times.begin(),times.end());

        for (vector<int> num : times) {
            int arrival = num[0];
            int departure = num[1];

            for (int i = 0; i < n; i++) {
                if (chairs[i] <= arrival) {
                    chairs[i] = departure;
                    if (arrival == targetFriendArrival) {
                        return i;
                    }
                    break;
                }
            }
        }

        return -1;
    }
};