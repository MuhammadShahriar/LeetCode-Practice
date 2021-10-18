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

int lev[210];
bool bro = 0;

void dfs ( TreeNode *u, int l, int x, int y )
{
    if ( !u ) return;
    lev[u->val] = l;
    if ( u->left && u->right ) {
        if ( ( u->left->val == x && u->right->val == y ) || ( u->left->val == y && u->right->val == x ) ) {
            bro = 1;
        }
    }
    dfs ( u->left, l+1, x, y );
    dfs ( u->right, l+1, x, y );
}


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        bro = 0;
        dfs(root, 0, x, y);
        
        return ( !bro && lev[x] == lev[y] );
    }
};