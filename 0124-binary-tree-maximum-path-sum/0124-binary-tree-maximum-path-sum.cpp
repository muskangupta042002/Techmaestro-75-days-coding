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
    int helper(TreeNode* root, int& diameter){
        if(root == NULL){
            return 0;
        }
        int lh=max(0,helper(root->left,diameter));
        int rh=max(0,helper(root->right,diameter));
        diameter=max(diameter,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int diameter=INT_MIN;
        helper(root,diameter);
        return diameter;
    }
};