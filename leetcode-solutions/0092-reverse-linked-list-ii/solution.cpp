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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL || left==right)return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* curr=dummy;
        int count=1;
        while(count<left)
        {
            curr=curr->next;
            count++;
        }
        ListNode* forward=curr->next;
        while(left<right)
        {
            ListNode * temp=forward->next;
            forward->next=temp->next;
            temp->next=curr->next;
            curr->next=temp;
            left++;
        }
        return dummy->next;
        
    }
};
