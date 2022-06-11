class Solution {
public:
 
    bool matchReplacement(string s, string sub, vector<vector<char>>& mapp) {
        int len=sub.size();
        unordered_map<char,unordered_set<char>>mp;
        for(auto x:mapp){
            mp[x[0]].insert(x[1]);
        }
        for(int i=0;i<=s.size()-len;i++){
            string str=s.substr(i,len);
            int f=0;
           for(int j=0;j<sub.size();j++){
               if(str[j]!=sub[j]){
                   if(mp.find(sub[j])!=mp.end()){
                   if(mp[sub[j]].count(str[j])==0){
                       f=1;
                       break;
                   }
                   }
                   else{
                       f=1;
                       break;
                   }
               }
              
           }
            if(f==0){
                return true;
            }
        }
        return false;
    }
};