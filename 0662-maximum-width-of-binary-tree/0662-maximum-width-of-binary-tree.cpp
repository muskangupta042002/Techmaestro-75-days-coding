/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * } ;
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        int ans=0;
        q.push({root, 0});
        while(!q.empty())
        {
            int n=q.size();
            int minn=q.front().second;
            int f,l;
            for(int i=0;i<n;i++)
            {
                int curr_id=q.front().second;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) f=curr_id;
                if(i==(n-1)) l=curr_id;
                if(node->left)
                    q.push({node->left, 2LL *curr_id+1});
                if(node->right)
                    q.push({node->right,  2LL *curr_id+2}); 
            }
            ans=max(ans,l-f+1);
            
        }
        return ans;
        
    }
};