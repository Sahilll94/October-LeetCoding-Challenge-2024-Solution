// Question Link : https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06

// Solution ->

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // We considered s1 to be have more length then s2;
        if(s1.length()<s2.length())
        {
            swap(s1,s2);
        }

        // Created two vector to use two pointer approach on both to check whether the first and last are same or not;
        vector<string>v1;
        vector<string>v2;

        // spliting the string s1;
        stringstream ss1(s1);
        string token;
        while(ss1>>token)
        {
            v1.push_back(token);
        }

        stringstream ss2(s2);
        string token1;
        while(ss2>>token1)
        {
            v2.push_back(token1);
        }

        // two pointers on v1(s1) vector;
        int i=0;
        int j=v1.size()-1;

        // two pointers on v2(s2) vector;
        int k=0;
        int l=v2.size()-1;

        // for prefix;
        while(i<v1.size() && k<v2.size() && v1[i]==v2[k])
        {
            i++;
            k++;
        }

        // for suffix
        while(l>=k && v1[j]==v2[l])
        {
            j--;
            l--;
        }


        return l<k;


    }
};