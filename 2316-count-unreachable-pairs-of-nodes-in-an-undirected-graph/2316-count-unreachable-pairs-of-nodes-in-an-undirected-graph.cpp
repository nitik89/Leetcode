class Solution {
public:
    long long temp;
    void getAns(long long x,unordered_map<long long,vector<long long>>&edg,vector<long long>&vis){
        temp++;
        vis[x]=1;
        for(auto y:edg[x]){
            if(!vis[y]){
                getAns(y,edg,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<long long,vector<long long>>mp;
        for(auto x:edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<long long>vis(n,0);
        vector<long long>te;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp=0;
                getAns(i,mp,vis);
                te.push_back(temp);
                sum+=temp;
            }
            }
        if(te.size()==1){
            return 0;
        }
        long long tot=0;
        for(auto x:te){
            int v=sum-x;
            tot+=v*x;
        }
        return tot/2;
    }
};