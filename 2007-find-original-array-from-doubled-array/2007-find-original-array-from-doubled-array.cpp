class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        if(ch.size()==1){
            return {};
        }
        sort(ch.begin(),ch.end());
        unordered_map<int,int>mp;
        for(auto x:ch){
            mp[x]++;
        }
        vector<int>ans;
        for(int i=0;i<ch.size();i++){
            if(mp[ch[i]]>0&&mp[2*ch[i]]>0){
                if(ch[i]==0&&mp[ch[i]]%2!=0){
                    continue;
                }
                ans.push_back(ch[i]);
                mp[ch[i]]--;
                mp[2*ch[i]]--;
            }
        }
        for(auto x:mp){
            // cout<<x.first<<" "<<x.second<<"\n";
            if(x.second>0){
                
                return {};
            }
        }
        return ans;
    }
};