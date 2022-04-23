class Solution {
public:
    vector<int>sm;
    bool getAns(int finalbit,int currbit,vector<int>&nums,int k,int target,int idx){
       
        if(finalbit==currbit){
            return true;
        }
         if(idx>=nums.size()){
            return false;
        }
        for(int i=0;i<sm.size();i++){
            if(sm[i]+nums[idx]==target){
                sm[i]+=nums[idx];
                if(getAns(finalbit,currbit|(1<<i),nums,k,target,idx+1)){
                    return true;
                }
                sm[i]-=nums[idx];
            }
            else if(sm[i]+nums[idx]<target){
                sm[i]+=nums[idx];
                if(getAns(finalbit,currbit,nums,k,target,idx+1)){
                    return true;
                }
                sm[i]-=nums[idx];
            }
            
           if(sm[i]==0){
               return false;
           }
                
        }
        return false;
       
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(auto x:nums){
            sum+=x;
        }
        int finalbit=(1<<k)-1;
        sm.resize(k,0);
        int target=sum/k;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        if(sum%k!=0){
            return false;
        }
        return getAns(finalbit,0,nums,k,target,0);
    }
};