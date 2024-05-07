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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* prev = NULL; // maintain the last element of first half

        while(fastptr != NULL && fastptr->next != NULL) //Find Middle of LL
        {
            prev = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        if(fastptr != NULL) 
        {
            prev = slowptr;
            slowptr = slowptr->next;
        }
        prev->next = NULL;
        prev->next = rev(slowptr);

        ListNode* temp = head;
        prev = prev->next;

        while(prev != NULL)
        {
            if(prev->val != temp->val) return false;
            prev = prev->next;
            temp = temp->next;
        }

        return true;
    }
};