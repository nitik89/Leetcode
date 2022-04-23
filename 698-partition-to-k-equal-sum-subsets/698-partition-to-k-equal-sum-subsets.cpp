class Solution {
public:
    
    int dp[1<<17-1][17];
    bool getAns(int finalbit,int currbit,int csum,vector<int>&nums,int k,int target,int count){
       if(currbit==finalbit){
          
           return count==k;
       }
        if(dp[currbit][count]!=-1){
            return dp[currbit][count];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]+csum==target&&(((1<<i)&currbit)!=(1<<i))){
               if(getAns(finalbit,currbit|(1<<i),0,nums,k,target,count+1)){
                   return dp[currbit][count]=true;
               }
            }
            else if(nums[i]+csum<target&&(((1<<i)&currbit)!=(1<<i))){
                 if(getAns(finalbit,currbit|(1<<i),csum+nums[i],nums,k,target,count)){
                     return dp[currbit][count]=true;
                 }
            }
        }
        return dp[currbit][count]=false;
       
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(auto x:nums){
            sum+=x;
        }
        int finalbit=(1<<n)-1;
      
        int target=sum/k;
        if(sum%k!=0){
            return false;
        }
        memset(dp,-1,sizeof dp);
        return getAns(finalbit,0,0,nums,k,target,0);
    }
};