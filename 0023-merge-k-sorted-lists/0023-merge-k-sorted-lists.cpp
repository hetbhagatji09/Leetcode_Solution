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
struct mycmp{
    bool operator()(ListNode *l1,ListNode *l2){
        return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        priority_queue<ListNode *,vector<ListNode *>,mycmp>q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr)
                q.push(lists[i]);
        }
        while(!q.empty()){
            ListNode *smallest=q.top();
            tail->next=smallest;
            tail=tail->next;
            if(smallest->next!=nullptr){
                q.push(smallest->next);
            }
            q.pop();
        }
        return dummy->next;
    }
};