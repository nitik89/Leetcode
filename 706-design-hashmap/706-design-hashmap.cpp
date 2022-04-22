class Node{
    public:
    int key,val;
    Node* next;
    
    Node(int k,int v,Node* nx){
        key=k;
        val=v;
        next=nx;
    }
};
class MyHashMap {
public:
    int sz=101;
    vector<Node*>vec;
    MyHashMap() {
        vec.resize(1001,NULL);
    }
    int getIndex(int idx){
        return idx%sz;
    }
    Node* contains(int idx,int k){
        Node* t=vec[idx];
        while(t!=NULL){
            if(t->key==k){
                return t;
            }
            t=t->next;
        }
        return NULL;
    }
    
    void put(int key, int value) {
        int i=getIndex(key);
        Node* yes=contains(i,key);
        if(yes!=NULL){
            yes->val=value;
        }
        else{
            Node* node=new Node(key,value,vec[i]);
            vec[i]=node;
        }
        
    }
    
    int get(int key) {
        int i=getIndex(key);
        Node* node=contains(i,key);
        if(node==NULL){
            return -1;
        }
        return node->val;
        
    }
    
    void remove(int key) {
        int i=getIndex(key);
        Node* t=vec[i];
        if(t==NULL){
            return;
        }
        Node* prev=NULL;
        if(t->key==key){
            vec[i]=t->next;
            return;
        }
        while(t!=NULL){
            if(t->key==key){
                prev->next=t->next;
                break;
            }
            prev=t;
            t=t->next;
        }
        if(prev==NULL){
            vec[i]=t->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */