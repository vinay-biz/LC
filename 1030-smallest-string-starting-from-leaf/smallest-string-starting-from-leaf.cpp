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
    void helper(TreeNode* root, string curr, string& ans)
    {
        if(root == NULL) return;

        curr = char(root->val + 97) + curr;

        if(root->left==NULL && root->right == NULL)
        {
            if(ans == "" || ans > curr) ans = curr;
        }

        if(root->left != NULL) helper(root->left,curr,ans);
        if(root->right != NULL) helper(root->right,curr,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        helper(root,"", ans);
        return ans;
    }
};