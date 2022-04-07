class Solution {
public:
    int dp[2001][1001];
    int getAns(vector<vector<int>>& piles,int k,int idx){
        if(idx==piles.size()||k==0){
            return 0;
        }
        if(dp[k][idx]!=-1){
            return dp[k][idx];
        }
        int exc=getAns(piles,k,idx+1);
        int inc=INT_MIN,sum=0;
        for(int i=0;i<min((int)piles[idx].size(),k);i++){
            sum+=piles[idx][i];
            inc=max(inc,sum+getAns(piles,k-(i+1),idx+1));
        }
        return dp[k][idx]=max(exc,inc);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
       return getAns(piles,k,0);
        
    }
};