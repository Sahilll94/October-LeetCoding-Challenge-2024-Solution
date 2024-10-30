// Question Link : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22

// Solution -> 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            long long levelsum=0;
            level++;//counting level

            for(int i=0;i<size;i++){
                //traversing each node at the level
                TreeNode* node=q.front();
                q.pop();

                levelsum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(pq.size() < k) pq.push(levelsum);
            else if(pq.size()==k && levelsum > pq.top()){
                pq.pop();
                pq.push(levelsum);
            }

        }
        if(level<k) return -1;
        return pq.top();
    }
};