class Solution {
public:
    int dp[21][10001];
    int getAns(vector<int>&rods,int i,int sum){
        if(i==rods.size()){
            if(sum==0){
                return 0;
            }
            else{
                return -1e5;
            }
        }
        if(dp[i][sum+5000]!=-1){
            return dp[i][5000+sum];
        }
        int a=getAns(rods,i+1,sum);
        int b=getAns(rods,i+1,sum-rods[i]);
        int c=getAns(rods,i+1,sum+rods[i])+rods[i];
        return dp[i][5000+sum]=max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
    memset(dp,-1,sizeof dp);
       return getAns(rods,0,0);
    }
};