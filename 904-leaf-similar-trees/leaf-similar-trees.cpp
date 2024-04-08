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
    void helper(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL) return;

        if(root->left == NULL && root->right == NULL) ans.push_back(root->val);

        helper(root->left,ans);
        helper(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;

        helper(root1,t1);
        helper(root2,t2);

        return t1==t2;
    }
};