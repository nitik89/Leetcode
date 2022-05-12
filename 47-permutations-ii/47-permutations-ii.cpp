class Solution {
public:
    void getUnique(int c,int t,vector<int>nums,vector<int>temp,map<int,int>m,vector<vector<int>>&ans){
        if(c>t){
            ans.push_back(temp);
            return;
        }
       int lo=m[nums[c]];
        for(int i=lo+1;i<temp.size();i++){
            if(temp[i]==INT_MIN){
            temp[i]=nums[c];
            m[nums[c]]=i;
            
            getUnique(c+1,t,nums,temp,m,ans);
                temp[i]=INT_MIN;
                m[nums[c]]=lo;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=-1;
            }
        }
        vector<int>temp(nums.size(),INT_MIN);
        int lo=-1;
        getUnique(0,nums.size()-1,nums,temp,m,ans);
        return ans;
    
    }
};