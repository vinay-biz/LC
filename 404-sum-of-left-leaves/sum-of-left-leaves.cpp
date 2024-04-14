
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;

        int sum = 0;
        if(root->left!=NULL && root->left->left==NULL && root->left->right == NULL) sum = sum + root->left->val;

        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};