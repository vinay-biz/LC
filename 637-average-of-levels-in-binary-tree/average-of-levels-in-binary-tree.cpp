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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            double sum = 0;
            double count = 0;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;
                count++;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            double avg = (double)sum/count;
            ans.push_back(avg);
            count = 0;
            sum = 0;
        }
        return ans;
    }
};