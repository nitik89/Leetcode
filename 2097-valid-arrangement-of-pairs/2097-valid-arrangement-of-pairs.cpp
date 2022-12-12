class Solution {
public:
    void dfs(int node,vector<vector<int>>&vec,unordered_map<int,vector<int>>&mp,int pre){
        
         auto& adj = mp[node];
        while(adj.size()) {
            int adjnode = adj.back();
            adj.pop_back();
            dfs(adjnode,vec,mp,node);
            
        }
        if(pre!=-1){
        vec.push_back({pre,node});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>indeg;
        for(auto x:pairs){
            int a=x[0],b=x[1];
            mp[a].push_back(b);
            indeg[a]++;
            indeg[b]--;
            }
        int s=-1;
        for(auto x:indeg){
            if(x.second>0){
                s=x.first;
                break;
            }
        }
        vector<int>vec;
        if(s==-1){
            s=pairs[0][0];
        }
        // cout<<s<<" ";
         vector<vector<int>>ans;
        dfs(s,ans,mp,-1);
       reverse(ans.begin(),ans.end());
       
        
        return ans;
    }
};