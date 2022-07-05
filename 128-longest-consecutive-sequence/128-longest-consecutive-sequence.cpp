class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>mp;
       for(auto x:nums){
           mp[x]=1;
       }
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(nums[i]-1)==mp.end()){
            int count=0;
            int temp=nums[i];
            while(mp.find(temp+1)!=mp.end()){
               temp=temp+1;
                count++;
            }
                mx=max(mx,count);
            
            
        }
        
        }
        return mx==INT_MIN?0:mx+1;
        
        
        
    }
};