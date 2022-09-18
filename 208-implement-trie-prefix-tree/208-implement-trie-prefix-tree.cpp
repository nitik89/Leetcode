class Node{
    public:
    Node* child[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        flag=false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* t=root;
        for(int i=0;i<word.size();i++){
            if(t->child[word[i] - 'a']==NULL){
                t->child[word[i] - 'a']=new Node();
            }
            
            t=t->child[word[i] - 'a'];
        }
        t->flag=true;
    }
    
    bool search(string word) {
        Node* t=root;
       
        for(int i=0;i<word.size();i++){
            if(t->child[word[i] - 'a']==NULL){
                return false;
            }
            t=t->child[word[i] - 'a'];
        }
        return t->flag;
    }
    
    bool startsWith(string prefix) {
        Node* t=root;
        for(int i=0;i<prefix.size();i++){
            if(t->child[prefix[i] - 'a']==NULL){
                return false;
            }
            t=t->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */