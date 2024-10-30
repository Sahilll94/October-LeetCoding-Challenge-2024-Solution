// Question Link : https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16

// Solution -> 


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        string s="";

        priority_queue<pair<int,char>>Heap;

        if(a>0)
        {
            Heap.push({a,'a'});
        }

        if(b>0)
        {
            Heap.push({b,'b'});
        }

        if(c>0)
        {
            Heap.push({c,'c'});
        }

        while(!Heap.empty())
        {
            int currCharCount = Heap.top().first;
            char currChar = Heap.top().second;
            Heap.pop();

            if(s.size()>= 2 && s[s.size()-1]==currChar && s[s.size()-2]==currChar)
            {
                if(Heap.empty())
                {
                    break;
                }

                int nextCharCount = Heap.top().first;
                char nextChar = Heap.top().second;
                Heap.pop();

                s.push_back(nextChar);
                nextCharCount--;

                if(nextCharCount>0)
                {
                    Heap.push({nextCharCount,nextChar});
                }

            }
            else
            {
                s.push_back(currChar);
                currCharCount--;
            }

            if(currCharCount>0)
            {
                Heap.push({currCharCount,currChar});
            }
        }

        return s;
    }
};