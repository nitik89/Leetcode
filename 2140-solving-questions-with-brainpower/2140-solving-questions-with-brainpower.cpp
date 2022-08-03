class Solution {
public:
    long long dp[100000];
    long long getAns(vector<vector<int>>&q,int i){
        if(i>=q.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long x=getAns(q,i+1);
        long long inc=getAns(q,i+q[i][1]+1)+q[i][0];
        return dp[i]=max(x,inc);
    }
    long long mostPoints(vector<vector<int>>& q) {
        memset(dp,-1,sizeof dp);
        return getAns(q,0);
    }
};