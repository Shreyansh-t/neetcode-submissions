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

    void insert(TreeNode* root, int val){
        if(!root){
            return ;
        }

        if(root->val < val){
            if(!root->right){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return ;
            }
            else return insert(root->right, val);
        }
        else{
            if(!root->left){
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return ;
            }
            else{
                return insert(root->left, val);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        return root;
    }
};