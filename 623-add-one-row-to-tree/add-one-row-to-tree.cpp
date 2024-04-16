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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* node = new TreeNode(val,root,NULL);
            return node;
        }
        queue<pair<TreeNode*,int>> q; //Node,level
        q.push({root,1});

        while(!q.empty())
        {
           TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();

                if(level == (depth-1))
                {
                    TreeNode* leftSub = node->left;
                    TreeNode* rightSub  = node->right;
            
                    node->left = new TreeNode(val,leftSub,NULL);
                    node->right = new TreeNode(val,NULL,rightSub);
                }

                if(level == depth) return root;

                if(node->left != NULL) q.push({node->left,level+1});
                if(node->right != NULL) q.push({node->right,level+1});
        }

        return root;
    }
};