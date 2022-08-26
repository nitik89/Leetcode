class Solution {
public:
    int dp[41][(1<<10)+1];
    int mod=1e9+7;
    
    // vector<vector<int>>vec(41,vector<int>());
    int getAns(vector<vector<int>>&vec,int mask,int no,int n){
        // cout<<mask<<" ";
         if(mask==((1<<n)-1)){
            return 1;
            }
        if(no>40){
           
            return 0;

        }
        if(dp[no][mask]!=-1){
            return dp[no][mask];
        }
        int cnt=0;
   cnt=cnt%mod+getAns(vec,mask,no+1,n);
        for(auto x:vec[no]){
            if(mask&(1<<x)) continue;
           
                cnt=cnt%mod+getAns(vec,mask|(1<<x),no+1,n);
            
        }
        return dp[no][mask]=cnt%mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof dp);
        vector<vector<int>>vec(41, vector<int>());
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                vec[hats[i][j]].push_back(i);
            }
        }
       return getAns(vec,0,1,hats.size());
    }
};