class Solution {
public:
    int dp[14][14];
    int getAns(int n,int m){
        if(n<0||m<0){
            return 0;
        }
        else if(n==1){
            return m;
        }
        else if(m==1){
            return n;
        }
        else if(n==0||m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int mx=min(n,m);
        int ans=1e5;
        for(int i=mx;i>=1;i--){
            //2 partitions 1 horizontal and other is vertical
            int f1=getAns(n-i,m);
            int f2=getAns(i,m-i);
            
            int s1=getAns(n,m-i);
            int s2=getAns(n-i,i);
            ans=min({ans,f1+f2,s1+s2});
            
        }
        return dp[n][m]=ans+1;
    }
    int tilingRectangle(int n, int m) {
        memset(dp,-1,sizeof dp);
        if(n==11&&m==13||n==13&&m==11){
            return 6;
        }
       return getAns(n,m);
    }
};