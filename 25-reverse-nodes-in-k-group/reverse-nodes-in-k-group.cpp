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
    void rev(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* KthNode(ListNode* head,int k)
    {
        k= k-1; //because we ahve to move by k-1 nodes
        ListNode* temp = head;
        for(int i=0; i<k; i++)
        {
            temp = temp->next;
            if(temp == NULL) return NULL;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* kth = KthNode(curr,k); //find the Kth Node if it exists
            
            if(kth == NULL) //if Kth node dosen't exists from the current
            { //Only if LL size is greater than K do we need to set it
                if(prev != NULL) prev->next = curr; 
                break;
            }
            
            next = kth->next; // so that we can continue moving forward later
            kth->next = NULL; //detach it to make a k size linked list 

            rev(curr);

            if(curr == head) head = kth; // In case it was first k, set head
            else prev->next = kth; // else attach the pervious to the newly rev LL

            prev = curr;
            curr = next;
        }

        return head;
    }
};