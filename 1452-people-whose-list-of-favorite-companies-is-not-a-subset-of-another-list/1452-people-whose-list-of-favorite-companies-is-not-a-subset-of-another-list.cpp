class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fav) {
        int c=0;
        unordered_map<string,int>mp;
        unordered_map<int,int>mp1;
       
        int j=0;
        for(auto x:fav){
            for(int i=0;i<x.size();i++){
                string str=x[i];
                if(mp.count(str)==0){
                    c++;
                    mp[str]=c;
                }}
            j++;
        }
        vector<bitset<50001>>vec;
       for(auto x:fav){
             bitset<50001> b;//making a bitset of 50001 bits
            for (const auto &c: x) {
                b[mp[c]] = 1;
            }
           vec.push_back(b);
       }
         vector<int>ans;
        for(int i=0;i<fav.size();i++){
            int cnt=1;
        
            for(int j=0;j<fav.size();j++){
                if(i!=j){
                    
                    if((vec[i]&vec[j])==vec[i]){
                        cnt--;
                        break;
                    }
                }
            }
            if(cnt==1)ans.push_back(i);
        }
        return ans;
        
    }
};