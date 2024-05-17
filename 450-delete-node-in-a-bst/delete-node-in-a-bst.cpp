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
    TreeNode* findLeftmost(TreeNode* root) {
        if(root->left == NULL) return root;
        return findLeftmost(root->left);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* leftmost = findLeftmost(root->right);//find the smallest number on right tree
        leftmost->left = root->left; 

        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root; 

        if(root->val == key) return helper(root); //Incase starting node is target
        TreeNode* ans = root;

        while(root != NULL) { //Search for key and apply the deletion function
            if(key < root->val) { //will be on the left side then
                if(root->left != NULL && root->left->val == key) root->left = helper(root->left);
                else root = root->left;
            }

            else {
                if(root->right != NULL && root->right->val == key) root->right = helper(root->right);
                else root = root->right;
            }
        }
        return ans;
    }
};