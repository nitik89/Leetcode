class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto x:queries){
            int k=x[0];
            int t=x[1];
            vector<pair<string,int>>vec;
            for(int i=0;i<nums.size();i++){
                string str=nums[i];
                string my=str.substr(str.size()-t);
                vec.push_back({my,i});
                
            }
            sort(vec.begin(),vec.end());
            // for(auto x:vec){
            //     cout<<x.first<<" ";
            // }
            // cout<<"\n";
            ans.push_back(vec[k-1].second);
        }
        return ans;
    }
};