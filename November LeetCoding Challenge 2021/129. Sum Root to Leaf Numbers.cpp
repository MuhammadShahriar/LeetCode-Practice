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

void dfs ( TreeNode* u, int val )
{
    
    if ( !u->left && !u->right ) {
        ans += (val*10) + u->val;
        return;
    }
    
    if(u->left) dfs ( u->left, ( val * 10 ) + u->val );
    if(u->right) dfs ( u->right, ( val * 10 ) + u->val );
}


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};