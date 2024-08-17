/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root)
    {
        if(root == NULL) return; //Base case

        if(root->left) {  //If left exists right also exits
            root->left->next = root->right;
            
            if(root->next != NULL) //If its not a corner root its right exists  
                root->right->next = root->next->left;
            else
                root->right->next = NULL;
        }

        helper(root->left);
        helper(root->right);
    }
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        root->next = NULL;
        helper(root);
        return root;
    }
};