class Solution {
public:
    int dp[11][2][1<<10+1];
    int dfs(int i,int tight,string &str,int mask){
        if(i>=str.size()){
            // cout<<(mask!=0)<<" ";
            return mask!=0;
        }
        if(dp[i][tight][mask]!=-1){
            return dp[i][tight][mask];
        }
        int cnt=0;
        if(tight==1){
            for(int j=0;j<=(str[i] - '0');j++){
                // cout<<j<<" ";
                if((mask&(1<<j)))continue;
                
                 int newmask = (mask == 0 && j == 0 ? mask : (mask | (1 << j)));
               if(j==(str[i] - '0')){
                  cnt+=dfs(i+1,1,str,newmask);
               } 
                else{
                    cnt+=dfs(i+1,0,str,newmask);
                }
            }
        }
        else{
           for(int j=0;j<=9;j++){
               
               if((mask&(1<<j)))continue;
                int newmask = (mask == 0 && j == 0 ? mask : (mask | (1 << j)));
               cnt+=dfs(i+1,0,str,newmask);
           }
        }
        return dp[i][tight][mask]=cnt;
    }
    int countSpecialNumbers(int n) {
        string str=to_string(n);
        memset(dp,-1,sizeof dp);
       return dfs(0,1,str,0);
    }
};