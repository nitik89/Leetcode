class Node{
    public:
    Node*child[26];
    int cnt;
    bool flag;
    Node(){
    for(int i=0;i<26;i++){
        child[i]=NULL;
    }
        flag=false;
        cnt=0;
    }
};
class Trie{
    public:
    Node * root;
    Trie(){
        root=new Node();
    }
    void insert(string str){
        Node* t=root;
        for(int i=0;i<str.size()&&t!=NULL;i++){
            if(t -> child[ str[i] - 'a' ]==NULL){
                t -> child[ str[i] - 'a' ] = new Node();
            }
            t = t -> child[str[i] - 'a'];
            t -> cnt++;
        }
        t -> flag = true;
    }
    int getCount(string str){
        Node * t = root;
        int sum=0;
        for(int i=0;i<str.size();i++){
            if(t -> child[str[i] - 'a'] == NULL){
                return sum;
            }
            t = t->child[str[i] - 'a'];
            sum+=t->cnt;
        } 
        return sum;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
       Trie *tr=new Trie();
        for(int i=0;i<words.size();i++){
            tr->insert(words[i]);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int v=tr->getCount(words[i]);
            ans.push_back(v);
        }
        return ans;
    }
};






