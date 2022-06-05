class Node{
    public:
    char ch;
    Node* prev;
    Node* next;
    Node(char t){
        ch=t;
        prev=NULL;
        next=NULL;
    }
};


class TextEditor {
public:
    Node* cursor;
    int size;
    TextEditor() {
        size=0;
        cursor=new Node('/');
    }
    
    void addText(string text) {
        Node* nxt=cursor->next;
        for(int i=0;i<text.size();i++){
              Node* curr=new Node(text[i]);
              curr->prev=cursor;
              cursor->next=curr;
            cursor=curr;
          }
        cursor->next=nxt;
        if(nxt){
            nxt->prev=cursor;
        }
            size+=text.size();
         
    }
    
    int deleteText(int k) {
        Node* save=cursor->next;
        int cnt=0;
        
        for(int i=k;i>=1&&cursor->ch!='/';i--){
            Node* pre=cursor->prev;
            Node* nxt=cursor->next;
            pre->next=nxt;
            if(nxt){
            nxt->prev=pre;
            }
            cursor=pre;
            cnt++;
        }
        
            
        return cnt;
    }
    
    string cursorLeft(int k) {
        string ans="";
        // Node* save=cursor->next;
        for(int i=k;i>=1&&cursor->ch!='/';i--){
            
             Node* pre=cursor->prev;
            cursor=pre;
            
        }
        // cursor->next=save;
        
        Node* t=cursor;
        for(int i=10;i>=1&&t->ch!='/';i--){
            
             ans+=t->ch;
            t=t->prev;
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        string ans="";
        
        for(int i=k;i>=1&&cursor->next!=NULL;i--){
            // str+=cursor->ch;
           cursor=cursor->next;
            
        }
         
        Node* t=cursor;
        for(int i=10;i>=1&&t->ch!='/';i--){
            ans+=t->ch;
           t=t->prev;
            
            
        }
        \
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */