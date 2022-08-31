class Solution {
public:
    int ans=INT_MIN;
    void dfs(int i,vector<int>&val,vector<vector<pair<int,int>>>&vec,int mxt,vector<int>&vis,int curr,int t){
         // cout<<i<<" "<<curr<<" "<<t<<"\n";
        if(t>mxt){
            return;
        }
        
         
        if(i==0){
            // cout<<t<<" ";
            ans=max(curr,ans);
            
            
        }
        
        
       vis[i]++;
        for(auto x:vec[i]){
            if(!vis[x.first]){
           dfs(x.first,val,vec,mxt,vis,curr+val[x.first],t+x.second);
            }
            else{
                dfs(x.first,val,vec,mxt,vis,curr,t+x.second);
            }
        }
        vis[i]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int mxt) {
      vector<vector<pair<int,int>>>vec(values.size());  
        for(auto x:edges){
            vec[x[0]].push_back({x[1],x[2]});
            vec[x[1]].push_back({x[0],x[2]});
        }
        vector<int>vis(values.size(),0);
        dfs(0,values,vec,mxt,vis,values[0],0);
        return ans;
    }
};