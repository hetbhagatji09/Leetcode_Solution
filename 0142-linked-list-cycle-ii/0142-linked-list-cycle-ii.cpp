/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>umap;
        ListNode *temp=head;
        while(temp!=nullptr){
            if(umap.find(temp)!=umap.end()){
                return temp;
            }
            umap[temp]=1;
            temp=temp->next;
        }
        return nullptr;


    }
};