class Solution {
public:
    int dp[501][501];
    int mod=1e9+7;
    long long getAns(int pos,int steps,int n){
        if(pos==0&&steps==0){
            return 1;
        }
        if(pos>=n||steps<0||pos<0){
            return 0;
        }
        if(dp[pos][steps]!=-1){
            return dp[pos][steps];
        }
        long long c1=getAns(pos+1,steps-1,n);
        long long c2=getAns(pos-1,steps-1,n);
        long long c3=getAns(pos,steps-1,n);
        return dp[pos][steps]=(c1%mod+c2%mod+c3%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof dp);
      return getAns(0,steps,arrLen);  
    }
};