class Solution {
public:
  unordered_map<int,int>mp;
    int getAns(vector<int>&stones,int idx,vector<int>&pre){
        // cout<<idx<<" ";
        if(idx==stones.size()){
            return 0;
        }
        if(idx==stones.size()-1){
            return pre[idx];
        }
        if(mp.find(idx)!=mp.end()) return mp[idx];
        
        int a=pre[idx]-getAns(stones,idx+1,pre);
        int b=getAns(stones,idx+1,pre);
       
        return mp[idx]=max(a,b);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>pre(n,0);
        pre[0]=stones[0];
        for(int i=1;i<stones.size();i++){
            pre[i]=pre[i-1]+stones[i];
        }
       
        return getAns(stones,1,pre);
    }
};