// Question Link : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04

// Solution -> 

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        // Sort the array
        sort(skill.begin(),skill.end());

        // take two pointers
        int i=0;
        int j=n-1;
        int sum = skill[i]+skill[j];

        long long int chem=0;

        while(i<j)
        {
            int currSkill=skill[i]+skill[j];

            if(currSkill!=sum)
            {
                return -1;
            }
            else
            {
                chem += (long long int)skill[i]*(long long int)skill[j];
            }
            i++;
            j--;
        }

        return chem;
    }
};