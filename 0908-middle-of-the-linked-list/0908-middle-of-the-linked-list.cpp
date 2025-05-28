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
        cout<<ct<<" ";
        return ct;
    }
    ListNode* middleNode(ListNode* head) {
        int ct=totalNodes(head);

       
            ListNode *temp=head;
            for(int i=0;i<(ct/2);i++){
                temp=temp->next;
            }
            return temp;
        
        
        
    }
};