/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) //count number of nodes
        {
            temp = temp->next;
            count++;
        }

        stack<int> st;
        temp = head;
        for(int i=0; i<count/2; i++) //add half to stack 
        {
            st.push(temp->val);
            temp = temp->next;
        }

        if(count%2 != 0) temp = temp->next;

        for(int i=0; i<count/2; i++)
        {
            if(st.top() != temp->val) return false;
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};