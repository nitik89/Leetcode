class Solution {
public: vector<int>sm;
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
    bool makesquare(vector<int>& nums) {
         int sum=0;
        int n=nums.size();
        for(auto x:nums){
            sum+=x;
        }
        int finalbit=(1<<4)-1;
        sm.resize(4,0);
        int target=sum/4;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        if(sum%4!=0){
            return false;
        }
        return getAns(finalbit,0,nums,4,target,0);
    }
};