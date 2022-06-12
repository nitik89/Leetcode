class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto x:tasks){
            mp[x]++;
        }
        int cnt=0;
        for(auto x:mp){
            int val=x.second;
            // cout<<val<<" ";
            if(val<=1){
                return -1;
            }
            if(val%3==0){
                cnt+=val/3;
            }
            
            else {
                cnt+=(val/3)+1;
            }
            
            
        }
        return cnt;
    }
};