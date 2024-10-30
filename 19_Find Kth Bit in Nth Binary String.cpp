// Question Link : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19

// Solution -> 

class Solution {
public:
    char findKthBit(int n, int k) {
        // base case
        if(n==1)
        {
            return '0';
        }

        int length = pow(2,n)-1;
        int mid = ceil(length/2.0);

        // Ceil(length/2.0) will give us the middle element which is always '1' as in question we are told to append '1' in the middle as Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1;
        if(k<mid)
        {
            return findKthBit(n-1,k);
        }
        else if(k==mid)
        {
            return '1'; //As I told you, middle element is '1', therefore, we will return 1;
        }
        else //(k>ceil(length/2.0))
        {
            char ans = findKthBit(n-1,length-(k-1)); //We went to Sn-1 like n=4 and k = 11, we are finding in s4, that means simply we can say the right part of the middle is reverse and inverted of left part right? Therefore, we can simply find that element(k) on left part and then flip it to simply find the right part's k value;
            if(ans == '1')
            {
                return '0';
            }
            else
            {
                return '1';
            }
        }

    }
};