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


int res = 0;

int dfs ( TreeNode* u, int lev )
{
    if ( !u ) return -1;
    if( !u->left && !u->right ) return 0;
    
    int l = dfs(u->left, lev+1);
    int r = dfs(u->right, lev+1);
    res = max ( res, l + r + 2 );
    return max(l, r) + 1;
}


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        dfs ( root, 0 );
        return res;
    }
};