class Solution {
public:
     int dp[501][150];
    int getAns(vector<int>&sl,int idx,int end,int n){
        if(idx>end||n==0){
            return 0;
        }
        if(dp[idx][n]!=-1){
            return dp[idx][n];
        }
        int exc=getAns(sl,idx+1,end,n);
        int inc=getAns(sl,idx+2,end,n-1)+sl[idx];
        return dp[idx][n]=max(exc,inc);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        memset(dp,-1,sizeof dp);
        int val1=getAns(slices,0,slices.size()-2,n/3); //the problem is always to get max no adjacent sum ie house robber ii
        memset(dp,-1,sizeof dp);
         int val2=getAns(slices,1,slices.size()-1,n/3);
        return max(val1,val2);
    }
};