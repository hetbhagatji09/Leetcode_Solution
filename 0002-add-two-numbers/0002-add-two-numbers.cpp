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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *ans=dummy;
        int carry=0;
        while(l1!=nullptr && l2!=nullptr){
            int sum= carry+(l1->val) + (l2->val);
            carry=sum/10;
            ListNode *newNode=new ListNode(sum%10);
            ans->next=newNode;
            l1=l1->next;
            l2=l2->next;
            ans=ans->next;
        }
        while(l1!=nullptr){
            int sum=carry+(l1->val);
            carry=sum/10;
            ListNode *newNode=new ListNode(sum%10);
            ans->next=newNode;
            l1=l1->next;
            ans=ans->next;
            
        }
        while(l2!=nullptr){
            int sum=carry+(l2->val);
            carry=sum/10;
            ListNode *newNode=new ListNode(sum%10);
            ans->next=newNode;
            l2=l2->next;
            ans=ans->next;
            
        }
        if(carry){
            ListNode *newNode=new ListNode(carry);
            ans->next=newNode;
        }
        return dummy->next;  
    }
};