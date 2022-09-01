class Solution {
public:
    int dp[201][201];
    int getAns(int s,int e){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int mn=INT_MAX;
        for(int i=s;i<=e;i++){
            int a1=i+getAns(s,i-1);
            int a2=i+getAns(i+1,e);
            mn=min(mn,max(a1,a2));
        }
        return dp[s][e]=mn;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
     return getAns(1,n);
    }
};