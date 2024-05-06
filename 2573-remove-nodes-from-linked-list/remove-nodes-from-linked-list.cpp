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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            while(!st.empty() && (st.top()->val) < temp->val) st.pop();

            st.push(temp);
            temp = temp->next;
        }

        ListNode* ans = st.top(); st.pop();
        ans->next = nullptr;

        while(!st.empty())
        {
            ListNode* dum = st.top(); st.pop();
            dum->next = ans;
            ans = dum;
        }

        return ans;
    }
};