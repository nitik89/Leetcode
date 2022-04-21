class Node{
    public:
    int val;
    Node* next;
    Node(int v,Node* nxt){
        val=v;
        next=nxt;
    }
};
class MyHashSet {
public:
    vector<Node*>vec;
    int sz=1001;
    MyHashSet() {
        vec.resize(1001,NULL);
    }
    int getIdx(int k){
        return k%sz;
    }
    
    void add(int key) {
        if(!contains(key)){
        int idx=getIdx(key);
         //we got a linked list here
        Node* my=new Node(key,vec[idx]);
        vec[idx]=my;
        }
    }
    
    void remove(int key) {
        int idx=getIdx(key);
        Node* temp=vec[idx];
        Node* prev=NULL;
        int fl=0;
        while(temp!=NULL){
            if(temp->val==key){
                fl=1;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL&&fl==1){
            vec[idx]=temp->next;
        }
        else if(fl==1){
            prev->next=temp->next;
        }
    }
    
    bool contains(int key) {
        int idx=getIdx(key);
        Node* t=vec[idx];
        while(t!=NULL){
            if(t->val==key){
                return true;
            }
            t=t->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */