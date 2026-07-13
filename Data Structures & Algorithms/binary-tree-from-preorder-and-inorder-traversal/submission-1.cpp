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

    unordered_map<int, int> mp;
    int n = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
        
        if(preS > preE || inS > inE){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preS]);
        int index = mp[preorder[preS]];
        int nelem = index - inS;

        root->left = dfs(preorder, inorder, preS+1, preS+nelem, inS, index-1);
        root->right = dfs(preorder, inorder, preS+nelem+1, preE, index+1, inE);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return dfs(preorder, inorder, 0, n-1, 0, n-1);
    }
};
