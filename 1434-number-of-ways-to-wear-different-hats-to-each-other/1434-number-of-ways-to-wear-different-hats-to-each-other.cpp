class Solution {
public:
    int dp[41][1<<10+1];
    int mod=1e9+7;
    int getAns(vector<vector<int>>&hats,int mask,int no){
        // cout<<mask<<" ";
        if(no>40){
            if(mask==((1<<hats.size())-1)){
                            return 1;
            }
            return 0;

        }
        if(dp[no][mask]!=-1){
            return dp[no][mask];
        }
        int cnt=0;
   cnt=cnt+getAns(hats,mask,no+1);
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                if(no==hats[i][j]){
                if(mask&(1<<i)) continue;
                cnt=cnt%mod+getAns(hats,mask|(1<<i),no+1);
                }
                
            }
        }
        return dp[no][mask]=cnt%mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof dp);
       return getAns(hats,0,1);
    }
};