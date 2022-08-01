class Solution {
public:
    int countPairs(vector<int>& del) {
        int mx=INT_MIN;
        for(auto x:del){
            mx=max(x,mx);
        }
        unordered_map<int,int>mp;
        // mp[0]=1;
        int mod=1e9+7;
        int val=pow(2,21);
        int cnt=0;
        for(int i=0;i<del.size();i++){
            int myval=del[i];
            int v=1;
            while(v<=val){
                cnt=cnt%mod+mp[v-myval];
                v*=2;
            }
            mp[myval]++;
        }
        return cnt%mod;
    }
};