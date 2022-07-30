class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp;
        for(auto x:words2){
            //eo eoo 
            unordered_map<char,int>temp;
            for(auto y:x){
                temp[y]++;
            }
            for(auto x:temp){
                if(mp.find(x.first)!=mp.end()){
                    mp[x.first]=max(temp[x.first],mp[x.first]);
                }
                else{
                    mp[x.first]=temp[x.first];
                }
            }
        }
        
        
       
        vector<string>ans;
        for(auto x:words1){
            unordered_map<char,int>save=mp;
            for(auto y:x){
                if(mp.find(y)!=mp.end()){
                mp[y]--;
                }
            }
            int t=0;
            for(auto x:mp){
                if(x.second>0){
                    t=1;
                    break;
                }
            }
            if(t==0){
                ans.push_back(x);
            }
            mp=save;
            
        }
        return ans;
    }
};