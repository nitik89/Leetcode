class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
     vector<vector<int>>ans;
        if(nums.size()==0){
         return ans;   
        }
     sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++){
         // cout<<i<<" ";
         int j=i+1;
         int target=0-nums[i];
         int m=nums.size()-1;
         while(j<nums.size()&&j<m){
             if(nums[j]+nums[m]==target){
                 ans.push_back({nums[i],nums[j],nums[m]});
                 int f=j;
                 j++;
                 while(j<m&&nums[f]==nums[j]){
                 j++;
                 }
                 
                 int p=m;
                 m--;
                 while(m>j&&nums[m]==nums[p]){
                     m--;
                 }
                 
                 
             }
             else if(nums[j]+nums[m]>target){
                 m--;
              }
             else{
                 j++;
             }
             
         }
         int k=i;
         i++;
         // int k=i+1;
         while(i<nums.size()&&nums[i]==nums[k]){
             i++;
         }
         i--;
         
     }   
        return ans;
    }
};