// Question Link : https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02


// Solution -> 

class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans (n,0);
        vector<pair<int,int>>mpp;

        // Inserted all the elements with their index in mpp vector;
        for(int i=0;i<n;i++)
        {
            mpp.push_back({arr[i],i});
        }

        // sorting the mpp vector on the basis of the key (first);
        sort(mpp.begin(),mpp.end(), [](pair<int,int>a,pair<int,int>b)
        {
            return a.first < b.first;
        });

        sort(arr.begin(),arr.end(),[](int a,int b)
        {
            return a < b;
        });

        // mapping the rank on ANS vector as per the sorted mpp value;
        int rank = 1;
        for(int i=0;i<n;i++)
        {
            if(i!=0 && mpp[i].first==mpp[i-1].first)
            {
                ans[mpp[i].second]=rank-1; //We won't increment the rank;
            }
            else{
                ans[mpp[i].second]=rank;
                rank+=1;
            }
        }

        return ans;
    }
};

