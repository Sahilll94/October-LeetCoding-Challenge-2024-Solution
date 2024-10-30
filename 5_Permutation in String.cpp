// Question Link : https://leetcode.com/problems/permutation-in-string/?envType=daily-question&envId=2024-10-05


// Solution ->  

class Solution {
public:

    bool TwoPointer(string s1, string s2)
    {
        int n = s1.size();
        int m=s2.size();

        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int j=0;
        int i=0;

        while(i<n && j<m)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
                return true;
            }
            else{
                j++;
            }
        }

        return false;

    }

    bool bruteForce(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if(n>m)
        {
            return false;
        }

        sort(s1.begin(),s1.end());

        // TC: O((m-n)*(n log n))
        // (m-n) for the FOR LOOP, (n logn) for the sorting;
        for(int i=0;i<=m-n;i++)
        {
            string substr = s2.substr(i,n);

            sort(substr.begin(),substr.end());

            if(s1 == substr)
            {
                return true;
            }
        }

        return false;
    }


    bool SlidingWindow(string s1, string s2)
    {
        int n =s1.size();
        int m = s2.size();

        // If, s1 is greater than s2 then it's not possible to find permutation of s1 in s2;
        if(n>m)
        {
            return false;
        }

        // we will use a frequency table for both the string and then compare it if not same then 
        vector<int>Freq_s1(26,0);
        vector<int>Freq_s2(26,0);

        // updating freq table as per the string's char;
        for(int i=0;i<n;i++)
        {
            Freq_s1[s1[i]-'a']++;
            Freq_s2[s2[i]-'a']++;
        }

        for(int i=0;i<m-n;i++)
        { 
            if(Freq_s1==Freq_s2)
            {
                return true;
            }
            else{
                Freq_s2[s2[i]-'a']--;
                Freq_s2[s2[i+n]-'a']++;
            }
        }


        return Freq_s1==Freq_s2;
    }

    
    bool checkInclusion(string s1, string s2) {
        // bool ans = bruteForce(s1,s2);
        bool ans = SlidingWindow(s1,s2);
        // bool ans = TwoPointer(s1,s2);

        return ans;


    }
};