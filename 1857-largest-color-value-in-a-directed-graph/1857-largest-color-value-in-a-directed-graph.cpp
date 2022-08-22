class Solution {
public:
    
    vector<vector<int>>grp;
    vector<vector<int>>ans;
    bool dfs(int i,string &colors,vector<int>&vis,vector<int>&vec){
        if(vis[i]){
            return false;
        }
       vis[i]=1;
        vec[i]=1;
        
         
        for(auto x:grp[i]){
            
             if(!dfs(x,colors,vis,vec)&&vec[x]){
                 // cout<<x<<" "<<i<<"\n";
                 return false;
             }
                else{
                    
                    //make answer here
                    for(int k=0;k<26;k++){
                        ans[i][k]=max(ans[i][k],ans[x][k]);
                    }
                }
            
        }
        vec[i]=0;
        ans[i][colors[i] - 'a']++;
        return true;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<int>vis(colors.size(),0);
        vector<int>vec(colors.size(),0);
        grp.resize(colors.size());
        for(auto x:edges){
            grp[x[0]].push_back(x[1]);
        }
        ans.resize(colors.size(),(vector<int>(26,0)));
        int yes=false;
        for(int i=0;i<colors.size();i++){
            if(!vis[i]){
            if(!dfs(i,colors,vis,vec)){
            return -1;
            }
                
                }
        }
        int an=INT_MIN;
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<26;j++){
                // cout<<ans[i][j]<<" ";
                an=max(ans[i][j],an);
            }
            // cout<<"\n";
        }
        return an;
        
        
    }
};