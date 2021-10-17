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

long long cnt = 0;
int t = 0;

vector<long long> dfs ( TreeNode *u )
{
    vector<long long> v;
    if ( !u ) return v;
    vector<long long> v1 = dfs ( u->left );
    vector<long long> v2 = dfs ( u->right );
    
    if(u->val == t) cnt++;
    
    for ( auto d : v1 ) {
        if ( t == u->val+d ) cnt++;
    }
    
    for ( auto d : v2 ) {
        if ( t == u->val+d ) cnt++;
    }
    
    
    v.push_back ( u->val );
    for ( auto d : v1 ) v.push_back ( d + u->val );
    for ( auto d : v2 ) v.push_back ( d + u->val );
    
    return v;
}

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt = 0;
        t = targetSum;
        dfs(root);
        
        return (int)cnt;
    }
};