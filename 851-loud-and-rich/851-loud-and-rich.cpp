class Solution {
public:
    vector<int>ans;
   int dfs(vector<vector<int>>&vec,vector<int>&q,int i){
       if(ans[i]!=-1){
           return ans[i];
       }
        // int an=INT_MAX;
        int curr=i;
       int v=i;
       ans[i]=i;
        for(auto x:vec[i]){
            
            int v=dfs(vec,q,x);
            // cout<<v<<" ";
            if(q[v]<q[ans[i]]){
                ans[i]=v;
            }
            
        }
       
         // cout<<an<<" ";
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>vec(n);
        for(auto x:richer){
            vec[x[1]].push_back(x[0]);
        }
        ans.resize(n,-1);
       
    
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
         dfs(vec,quiet,i); 
            }
            
        
        }
        return ans;
    }
};