class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<long long,int>mp;
        for(int i=0;i<nums.size()-1;i++){
            long long sum=0;
            for(int j=i;j<i+2;j++){
                sum+=nums[j];
               
            }
             mp[sum]++;
        }
        for(auto x:mp){
            if(x.second>=2){
                return true;
            }
        }
        return false;
        
    }
};