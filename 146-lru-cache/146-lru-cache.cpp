class Node{
     public:
    int value,key;
    Node* prev;
    Node* next;
   
    Node(int k,int val){
        value=val;
        key=k;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int cap=0,size=0;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head=NULL;
        tail=NULL;
    }
    void insert(Node* my){
        // Node* my=new Node(val);
        if(head==NULL){
            head=my;
            tail=my;
        }
        else{
            tail->next=my;
            my->prev=tail;
            tail=my;
        }
    }
    void delete_node(Node* node){
     if(node==head){
         head=head->next;
         if(head!=NULL){
         head->prev=NULL;
         }
         
     }
        else if(node==tail){
            if(node->prev!=NULL){
                node->prev->next=NULL;
            }
            tail=node->prev;
            
        }
        else{
            node->prev->next=node->next;
            if(node->next!=NULL){
                node->next->prev=node->prev;
            }
            
        }
        node->next=NULL;
        node->prev=NULL;
    }
    int get(int key) {
        // cout<<tail->value<<" ";
        // cout<<mp[key]->value<<" "<<key<<"\n";
        if(mp.find(key)!=mp.end()){
            int v=mp[key]->value;
            delete_node(mp[key]);
            insert(mp[key]);
            return v;
        }
        return -1;
    }
    
    
    void put(int key, int value) {
        //when new node comes
        if(mp.find(key)==mp.end()){
            Node* my=new Node(key,value);
            mp[key]=my;
             mp[key]->value=value;
            mp[key]->key=key;
            if(size<cap){
                // cout<<key<<" ";
                insert(my);
                size++;
             }
            else{
                // cout<<head->value<<" ";
                mp.erase(head->key);
               delete_node(head);
                insert(my);
            }
           
        }
        else{
             mp[key]->value=value;
            // cout<<head->value<<" ";
           delete_node(mp[key]);
            insert(mp[key]);
            //old node insert at tail
            }
        
        
       
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */