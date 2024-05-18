class Solution {
public:
    void findParent(TreeNode* root, unordered_map <TreeNode*,TreeNode*>& parent) {
        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != NULL) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right != NULL) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        unordered_map <TreeNode*,TreeNode*> parent;
        unordered_map <TreeNode*, bool> visited;
        findParent(root,parent);
        
        queue<TreeNode*> q;
        q.push(target);
        int currLevel = 0;

        while(!q.empty())
        {
            int size = q.size();
            if(currLevel == k) break;
            currLevel++;

            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != NULL && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right != NULL && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val != target->val) ans.push_back(curr->val);
        }

        return ans;    
    }
};