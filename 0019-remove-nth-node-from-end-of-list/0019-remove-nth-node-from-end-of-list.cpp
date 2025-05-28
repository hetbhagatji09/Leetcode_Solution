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
    int totalNodes(ListNode *head){
        ListNode *temp=head;
        int ct=0;
        while(temp!=nullptr){
            ct++;
            temp=temp->next;
        }
        return ct;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ct=totalNodes(head);
        int count=ct-n-1;
        ListNode *temp=head;
        if(ct==n){
            return head->next;;
        }
        for(int i=0;i<count;i++){
            temp=temp->next;
        }
        if(temp!=nullptr && temp->next!=nullptr)
        temp->next=temp->next->next;
        return head;
    }
};