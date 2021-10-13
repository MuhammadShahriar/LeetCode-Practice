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

void dfs ( TreeNode *u, int val ) 
{
    if (u->val == 0) {
        u->val = val;
        return;
    }
    
    if ( val < u->val ) {
        if ( !u->left  ) u->left = new TreeNode(0);
        dfs ( u->left, val );
    }
    else {
        if ( !u->right  ) u->right = new TreeNode(0);
        dfs (u->right, val);
    }
}


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        
        for ( int i = 1; i < preorder.size(); i++ ) {
            dfs ( root, preorder[i] );
        }
        
        return root;
    }
};