class Solution {
public:
    unordered_map<int,vector<int>>mp;
    Solution(vector<int>& nums){
        int idx=0;
        for(auto x:nums){
            
            mp[x].push_back(idx++);
        }
    }
    
    int pick(int target) {
        vector<int>vec=mp[target];
        int sz=vec.size();
        int idx=rand()%sz;
        return vec[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */