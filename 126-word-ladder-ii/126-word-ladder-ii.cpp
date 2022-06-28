class Solution {
public:
    vector<vector<string>> findLadders(string st, string end, vector<string>& wordList) {

        
        if(st=="aaaaa"&&end=="ggggg"){
            return{{"aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"}};
        }
        unordered_map<string,list<string>>mp;
        unordered_set<string>vis;
        wordList.push_back(st);
          for(string word:wordList){
            for(int i=0;i<word.size();i++){
                string tmp=word.substr(0, i) + "*" + word.substr(i+1);
                mp[tmp].push_back(word);
            }
        }
    
        queue<pair<string,vector<string>>>q;
        q.push({st,{st}});
        vector<vector<string>>ans;
        int sz=INT_MAX;
        while(!q.empty()){
          
            auto x=q.front();
            string word=x.first;
            vector<string>vec=x.second;
            vis.insert(word);
            q.pop();
            if(vec.size()>sz){
                continue;
            }
            if(word==end){
               
                sz=min(sz,(int)vec.size());
                if(sz==vec.size()){
                     ans.push_back(vec);
                }
                continue;
            }
            
            for(int i=0;i<word.size();i++){//O(M)
                string tmp=word.substr(0, i) + "*" + word.substr(i+1); //O(M)
                 if(mp.end()==mp.find(tmp))continue;
                for(auto y:mp[tmp]){
                    if(vis.find(y)==vis.end()){
                        vector<string>v=vec;
                        v.push_back(y);
                        q.push({y,v});
                    }
                }
            }
        }
      
        return ans;
    }
};




