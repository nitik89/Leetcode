class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][101];
    int getAns(int n,int m,int k,int i,int prev){
        // cout<<prev<<" ";
        if(k<0){
            
            return 0;
        }
        if(i==n){
            
            return k==0;
        }
        if(prev!=-1&&dp[k][i][prev]!=-1){
            return dp[k][i][prev];
        }
        int ans=0;
        if(prev==-1){
            for(int j=1;j<=m;j++){
                ans=ans%mod+getAns(n,m,k-1,i+1,j);
            }
        }
        else{
            for(int j=prev+1;j<=m;j++){
                
                    ans=ans%mod+getAns(n,m,k-1,i+1,j);
            }
            for(int j=1;j<=prev;j++){
                
                    ans=ans%mod+getAns(n,m,k,i+1,prev);
            }
            
            
        }
        if(prev==-1){
            return ans%mod;
        }
        return  dp[k][i][prev]=ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof dp);
       return getAns(n,m,k,0,-1);
    }
};