class Solution {
public:
    
        unordered_map<string,int>dis;
        unordered_map<string,vector<string>>grp;
    vector<vector<string>>ans;
    void dfs(string& x,vector<string>&path,string& begin){
        if(x==begin){
            
            ans.push_back(path);
            return;
        }
        for(auto &y:grp[x]){
            path.push_back(y);
            dfs(y,path,begin);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        
       for(auto &x:wordList){
           dis[x]=INT_MAX;
       }
        dis[beginWord]=0;
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty()){
            auto word=q.front();
            q.pop();
            
            for(int i=0;i<word.size();i++){
                for(char a='a';a<='z';a++){
                    string newword=word;
                    newword[i]=a;
                    if(dis.count(newword)&&newword!=word){
                    if(dis[word]+1<dis[newword]){
                        dis[newword]=dis[word]+1;
                        q.push(newword);
                        grp[newword].clear();
                        grp[newword].push_back(word);
                    }
                        else if(dis[word]+1==dis[newword]){
                            grp[newword].push_back(word);
                        }
                    }
                    
                }
                
            }
        }
        vector<string>path;
        path.push_back(endWord);
        dfs(endWord,path,beginWord);
        for(auto &x:ans){
            reverse(x.begin(),x.end());
        }
        return ans;
    }
};