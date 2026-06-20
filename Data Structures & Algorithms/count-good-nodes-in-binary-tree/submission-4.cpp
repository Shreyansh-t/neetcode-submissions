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

    int dfs(TreeNode* root, int maxi){
        if(!root) return 0;

        int ans = 0;
        if(root->val >= maxi){
            ans += 1;
        }
        maxi = max(root->val, maxi);
        ans += dfs(root->left, maxi);
        ans += dfs(root->right, maxi);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
