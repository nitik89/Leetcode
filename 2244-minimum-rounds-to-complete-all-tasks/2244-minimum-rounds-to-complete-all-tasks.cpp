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
            
            else if(val%3==2){
                cnt+=(val/3)+1;
            }
            else if(val%3==1){
                cnt+=(val/3)+1;
            }
            else if(val%2==0){
                cnt+=val/2;
            }
            else if(val%2==1){
                cnt+=(val/2);
            }
            
        }
        return cnt;
    }
};