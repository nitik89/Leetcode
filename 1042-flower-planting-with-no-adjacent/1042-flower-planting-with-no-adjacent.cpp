class Solution {
public:
    void dfs(int i,vector<vector<int>>&paths,vector<int>&ans){
        
        if(ans[i]){
            return;
        }
        for(int j=1;j<=4;j++){
            int br=1;
            for(auto x:paths[i]){
                if(ans[x]==j){
                    br=0;
                    break;
                }
            }
            if(br){
                ans[i]=j;
                break;
            }
        }
        for(auto x:paths[i]){
            dfs(x,paths,ans);
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       vector<int>ans(n+1,0);
        vector<vector<int>>vec(n+1);
        for(auto x:paths){
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==0){
                dfs(i,vec,ans);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};