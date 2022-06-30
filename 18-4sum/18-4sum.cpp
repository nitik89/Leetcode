class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            
            return {};
        }
        sort(nums.begin(),nums.end());
        
        int i=0;
        vector<vector<int>>ans;
        while(i<nums.size()-3){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
            long long sum=target-nums[i];
            long long start=i+1;
            while(start<nums.size()-2){
                long long sumfor2=sum-nums[start];
                long long idx=start+1;
                long long j=nums.size()-1;
                if(start==i+1||(start>0&&nums[start]!=nums[start-1])){
                while(idx<j){
                    if(nums[idx]+nums[j]>sumfor2){
                        j--;
                    }
                    else if(nums[idx]+nums[j]<sumfor2){
                        idx++;
                    }
                    else{
                        ans.push_back({nums[i],nums[start],nums[idx],nums[j]});
                        idx++;
                        j--;
                        while(idx<j&&nums[idx-1]==nums[idx]) idx++;
                        while(idx<j&&nums[j+1]==nums[j]) j--;
                    }
                    
                }
                    start++;
                }
                else{
                    start++;
                }
            
            }
                i++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};