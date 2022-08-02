class Solution {
public:
    int dp[15][1<<14];
    long long getAns(long long idx,vector<int>&nums1,vector<int>&nums2,int mask){
        if(idx>=nums1.size()){
            return 0;
        }
        if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
        long long ans=1e12;
        for(int i=0;i<nums2.size();i++){
            // cout<<mask<<" "<<(1<<i)<<"\n";
            if(mask&(1<<(i))){
                continue;
            }
            
               
                ans=min(ans,(nums1[idx]^nums2[i])+getAns(idx+1,nums1,nums2,(mask|(1<<i))));
            
        }
        return dp[idx][mask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        memset(dp,-1,sizeof dp);
      return getAns(0,nums1,nums2,0); 
    }
};