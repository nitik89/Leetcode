class Solution {
public:
    bool isPossible(vector<int>& nums) {
         unordered_map<int,int>sub;
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(mp[val]>0){
            if(sub[val-1]>0){
                sub[val]++;
                mp[val]--;
                sub[val-1]--;
            }
            else if(mp[val+1]>0&&mp[val+2]>0){
                mp[val]--;
                mp[val+1]--;
                mp[val+2]--;
                sub[val+2]++;
            }
           
                else{
                    // cout<<val<<" "<<i; 
                    return false;
                }
            }
        }
        return true;
    }
};