class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            int m=i;
            for(int j=0;j<nums[i].size();j++){
                mp[m].push_back(nums[i][j]);
                m++;
            }
        }
        vector<int>ans;
        for(auto x:mp){
            vector<int>vec=x.second;
            for(int i=vec.size()-1;i>=0;i--){
                ans.push_back(vec[i]);
            }
        }
        return ans;
    }
};