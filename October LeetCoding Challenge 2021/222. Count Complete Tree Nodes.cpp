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


int cnt;
void dfs ( TreeNode *u )
{
    if ( !u ) return;
    cnt++;
    
    dfs ( u->left );
    dfs ( u->right );
}


class Solution {
public:
    int countNodes(TreeNode* root) {
        cnt = 0;
        dfs ( root );
        return cnt;
    }
};