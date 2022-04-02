class Solution {
public:
    int dp[201][201];
    int getAns(vector<int>&nums,int idx,int k){
        if(idx==nums.size()){
            return 0;
        }
        if(k<0){
            return 1e9;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int mx=INT_MIN;
        int ans=INT_MAX;
        int sum=0;
        for(int i=idx;i<nums.size();i++){
            
            sum+=nums[i];
            mx=max(mx,nums[i]);
            // cout<<(i-idx+1)*mx-sum<<" ";
            ans=min(ans,(i-idx+1)*mx-sum+getAns(nums,i+1,k-1));
            
        }
        return dp[idx][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof dp);
        return getAns(nums,0,k);
    }
};