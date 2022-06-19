class Solution {
public:
    int cnt;
    // int dp[3001][3001];
    int getAns(int num,int k,int sum,int val,vector<vector<int>>&dp){
        if(num<0||k>sum){
            return 1e9;
        }
     if(num==0){
         
         return dp[num][k]=0;
     }
        if(dp[num][k]!=-1){
            return dp[num][k];
        }
        int mx=1e9;
        
        mx=min(mx,getAns(num,k+10,sum,val,dp));
        
        for(int i=1;i*k<=num;i++){
            mx=min(mx,getAns(num-i*k,k,sum,val,dp)+i);
        }
        
        
        return dp[num][k]=mx;
    }
    int minimumNumbers(int num, int k) {
        
        if(num==0){
            return 0;
        }
        if(k==0&&num%10==0){
            return 1;
        }
        if(k==0){
            return -1;
        }
        vector<vector<int>>dp(num+1,vector<int>(num+1,-1));
        
        cnt=INT_MAX;
        int ans=getAns(num,k,num,0,dp);
        return ans==1e9?-1:ans;
        
    }
};