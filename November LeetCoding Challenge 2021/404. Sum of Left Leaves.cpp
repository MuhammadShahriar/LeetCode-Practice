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

int ans = 0;
void dfs ( TreeNode* u, bool f1 )
{
    if ( !u ) return;
    if ( !u->left && !u->right ) {
        if ( f1 ) ans += u->val;
        return;
    }
    
    dfs ( u->left, 1 );
    dfs (u->right, 0);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};