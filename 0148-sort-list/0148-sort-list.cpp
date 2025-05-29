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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;

        }
        if(list1!=nullptr) tail->next=list1;
        if(list2!=nullptr) tail->next=list2;
        return dummy->next;
        
    }
    ListNode* findMiddle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *middle=findMiddle(head);
        ListNode *right=middle->next;
        middle->next=nullptr;
        ListNode *left=head;
        ListNode *leftPart=sortList(left);
        ListNode *rightPart=sortList(right);
        return mergeTwoLists(leftPart,rightPart);
    }
};