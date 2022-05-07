class Node{
    public:
    int val,freq,key;
    Node* next;
    Node* prev;
    Node(int k,int v,int f){
        val=v;
        freq=f;
        key=k;
        next=NULL;
        prev=NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
   
    List(){
        head=NULL;
        tail=NULL;
    }
  void add(Node* t){
      if(head==NULL){
          head=t;
          tail=t;
      }
      else if(tail!=NULL){
          tail->next=t;
          t->prev=tail;
          tail=t;
      }
  }
 
    void removeHead(){
        if(head==NULL){
            return;
        }
        else{
            if(head->next!=NULL){
            head=head->next;
            head->prev=NULL;
                if(head->next==NULL){
                    tail=head;
                }
            }
            else{
                head=NULL;
                tail=NULL;
            }
        }
    }
    void removeTail(){
        if(tail==NULL){
            return;
        }
        else if(tail->prev==NULL){
            tail=NULL;head=NULL;
        }
        else{
           tail=tail->prev; 
            tail->next=NULL;
           
        }
    }
    void removeAny(Node* t){
        Node* m=t->prev;
        Node* y=t->next;
        // cout<<t->val<<" ";
        if(m!=NULL){
        m->next=y;
        }
        if(y!=NULL){
        y->prev=m;
        }
        
    }
    void remove(Node* t){
        if(t==head){
            removeHead();
        }
        else if(t==tail){
            removeTail();
        }
        else{
            removeAny(t);
        }
    }
};
class LFUCache {
public:
    unordered_map<int,Node*>mp;//freq node list
    unordered_map<int,List*>getit; //get node list
    int cap,minfreq,size;
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=1;
        size=0;
    }
    
    int get(int key) {
        if(cap==0){
            return -1;
        }
        if(mp.find(key)==mp.end()){
            return -1;
        }
        else{
            Node* t=mp[key];
            int v=t->val;
            // cout<<v<<" ";
            List* my=getit[t->freq];
            if(my!=NULL){
            my->remove(t);
            }
            List* addIt=NULL;
            if(getit[t->freq+1]==NULL){
                addIt=new List();
            }   
            else{
                addIt=getit[t->freq+1];
            }
            if(getit[minfreq]->head==NULL){
                
                minfreq++;
                
            }
            addIt->add(t);
            t->freq++;
            getit[t->freq]=addIt;
            return v;
            
        }
    }
    
    void put(int key, int value) {
        // cout<<minfreq<<" ";
        if(mp.find(key)!=mp.end()){
            //exist krta hai
            Node* t=mp[key];
            List* mylist=getit[t->freq];
            mylist->remove(t);
            List* addIt=NULL;
            if(getit[t->freq+1]==NULL){
                addIt=new List();
            }
            else{
                addIt=getit[t->freq+1];
            }
            if(getit[minfreq]->head==NULL){
                minfreq++;
            }
            t->val=value;
            addIt->add(t);
            getit[t->freq+1]=addIt;            
            t->freq++;
            
           
        }
        else{
        int freq=1;
            //create a node 
            List* my=NULL;
            if(getit[freq]==NULL){
                 my=new List();
                
               }
            else{
                my=getit[freq];
            }
            
            if(size+1>cap){
               // cout<<minfreq<<" ";
               
                     // cout<<key<<" "<<value<<" "<<size<<"\n";
                    // cout<<getit[minfreq]->head->key<<" ";
                // cout<<minfreq<<" ";
                if(getit[minfreq]!=NULL){
                mp.erase(getit[minfreq]->head->key);
                     getit[minfreq]->removeHead();
                
                size--;
                if(getit[minfreq]==NULL){
                    minfreq++;
                }
                }
            
               
            }
            if(cap!=0){
                // cout<<key<<" "<<value<<"\n";
            minfreq=freq;
            Node* t=new Node(key,value,freq);
            my->add(t);   
            getit[minfreq]=my;
            mp[key]=t;
            size++;
            }
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */