class Solution {
public:
    bool match(string x,string pat){
        unordered_map<char,char>mp;
        unordered_map<char,int>mp1;
        for(int i=0;i<x.size();i++){
            if(mp.find(pat[i])==mp.end()){
                if(mp1.find(x[i])!=mp1.end()){
                    return false;   //the mapped should not occur earlier
                }
                mp[pat[i]]=x[i];
                mp1[x[i]]=1;
                
                
            }
            else {
                if(mp[pat[i]]!=x[i]){
                    return false;
                }
                
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      //isogram wala question lag rha hai yeh 
        vector<string>ans;
        for(auto x:words){
            if(match(x,pattern)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};