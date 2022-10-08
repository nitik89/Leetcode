class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX,dif=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int tar=target-nums[i];
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                if(nums[s]+nums[e]>tar){
                    int temp=nums[i]+nums[s]+nums[e];
                    int diff=abs(target-temp);
                    if(diff<dif){
                        ans=temp;
                        dif=abs(target-temp);
                    }
                    
                    e--;
                }
                else if(nums[s]+nums[e]==tar){
                    return target;
                }
                else{
                    int temp=nums[i]+nums[s]+nums[e];
                    int diff=abs(target-temp);
                    if(diff<dif){
                        ans=temp;
                        dif=abs(target-temp);
                    }
                    s++;
                }
            }
        }
        return ans;
    }
};