class Solution {
public:
    void dfs(vector<vector<int>>&vec,int i,int j){
        if(i<0||i>=vec.size()||j<0||j>=vec[0].size()||vec[i][j]==0||vec[i][j]==2) return ;
        
        if(vec[i][j]==1){
            // cout<<i<<" "<<j<<"\n";
        vec[i][j]=2;
        dfs(vec,i,j+1);
        dfs(vec,i,j-1);
        dfs(vec,i+1,j);
        dfs(vec,i-1,j);
            }
    }
    
    int check(vector<vector<int>>&grid){
        vector<vector<int>>vec=grid;
        for(int i=0;i<grid.size();i++){
            int o=0;
            for(int j=0;j<grid[0].size();j++){
                if(vec[i][j]==1){
                    o=1;
                    dfs(vec,i,j);
                    break;
                }
            }
            if(o==1){
                break;
            }
        }
       
        // cout<<"\n";
        int cnt1=0;
          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vec[i][j]==1){
                    
                    return true;
                }
                if(vec[i][j]==2){
                    cnt1=1;
                }
                
            }
          }
        if(!cnt1){
            return true;
        }
        return false;
        
    }
 
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       if(check(grid)){
           return 0;
       }
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                  
                  grid[i][j]=0;
                  // cout<<i<<" "<<j<<" "<<grid[i][j]<<"\n";
              if(check(grid)){
                  return 1;
              }
              grid[i][j]=1;
              }
          }
      }
        return 2;
    }
};





