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
    ListNode* rev (ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = rev(head);
        ListNode* dum = temp;
        int carry = 0;

        while(carry > 0 || temp != NULL)
        {
            int a = temp->val * 2;
            temp->val = a%10 + carry;
            carry = a/10;

            if(temp->next == NULL && carry != 0) {temp->next = new ListNode(carry); break;}
            temp = temp->next;
        }

        ListNode* ans = rev(dum);
        return ans;
    }

};