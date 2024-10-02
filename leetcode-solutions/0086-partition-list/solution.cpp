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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lowerHead =new ListNode(-1);
        ListNode* greaterHead=new ListNode(-1);
        ListNode* firstNode=lowerHead;
        ListNode* greaterNode=greaterHead;
        ListNode* temp=head;
        while(temp)
        {
            if(temp->val<x)
            {
                firstNode->next=temp;
                firstNode=temp;
            }
            else
            {
                greaterNode->next=temp;
                greaterNode=temp;
            }
            temp=temp->next;
        }
        greaterNode->next=NULL;
        firstNode->next=greaterHead->next;
        return lowerHead->next;
    }
};
