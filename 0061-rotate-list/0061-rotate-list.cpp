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
    int totalLength(ListNode *head){
        ListNode *temp=head;
        int ct=0;
        while(temp!=nullptr){
            ct++;
            temp=temp->next;
        }
        return ct;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int length=totalLength(head);
        if(head==nullptr) return head;
        k=k % length;
        if(head==nullptr || head->next==nullptr || k==0) return head;
        int jump=length-k-1;
        ListNode *temp1=head;
        while(temp1->next!=nullptr){
            temp1=temp1->next;
        }
        temp1->next=head;
        ListNode *temp2=head;
        for(int i=0;i<jump;i++){
            temp2=temp2->next;
        }
        ListNode *newHead=temp2->next;
        temp2->next=nullptr;
        return newHead;
        
    }
};