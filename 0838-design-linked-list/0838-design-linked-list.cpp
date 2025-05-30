class MyLinkedList {
public:
    class ListNode{
        public:
            int data;
            ListNode *next;
            ListNode(int val){
                data=val;
                next=nullptr;
            }
    };
    ListNode *head;
    int size;
    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
        if(head==nullptr || index>=size ||index<0) return -1;
        ListNode *temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->data;
        
    }
    
    void addAtHead(int val) {
        ListNode *newNode=new ListNode(val);
        ListNode *temp=head;
        newNode->next=head;
        head=newNode;
        size++;
        
        
    }
    
    void addAtTail(int val) {
        ListNode *newNode=new ListNode(val);
        if(head==nullptr){
            head=newNode;
            size++;
            return ;
        }
        else{
            ListNode *temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        
        size++;

        
    }
    
    void addAtIndex(int index, int val) {
        if(index>size || index<0) return ;
        ListNode *temp=head;
        ListNode *newNode=new ListNode(val);
        if(index==0){
          addAtHead(val);
          return;
        }
        else{
            for(int i=0;i<index-1;i++){
                temp=temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode *temp=head;
      
        if(index==0){
            head=head->next;
            size--;
            return;
        }
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */