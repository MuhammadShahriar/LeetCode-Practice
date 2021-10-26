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

void dfs ( TreeNode *u )
{
    if ( !u ) return;
    
    swap ( u->left, u->right );
    dfs ( u->left );
    dfs ( u->right );
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs (root);
        return root;
    }
};