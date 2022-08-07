class Solution {
public:
    unordered_map<int,int>mp;
    int getAns(vector<vector<int>>&vec,int n,int i,vector<int>&vis){
        if(mp.count(i)||vis[i]){
            return 0;
        }
        vis[i]=1;
        int cnt=0;
        for(auto x:vec[i]){
            
            cnt+=getAns(vec,n,x,vis);
        }
        return cnt+1;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        vector<vector<int>>vec(n);
        for(auto x:rest){
            mp[x]++;
        }
        for(auto x:edges){
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
            
        }
        vector<int>vis(n,0);
       return getAns(vec,n,0,vis);
    }
};