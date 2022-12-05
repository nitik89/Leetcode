class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int idx=0;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            
        }
       
        vector<int>res;
        for(auto &x:q){
            int a=x[0];
            int b=x[1];
            int ans=INT_MAX;
            int pre=-1;
            for(int i=1;i<=100;i++){
                if(mp[i].size()==0) continue;
                int idx2=lower_bound(mp[i].begin(),mp[i].end(),a)-mp[i].begin();
                if(idx2<mp[i].size()&&mp[i][idx2]<=b){
                    if(pre!=-1){
                        // cout<<i<<" "<<pre<<" "<<idx2<<"\n";
                        ans=min(ans,i-pre);
                    }
                    pre=i;
                }
                
            }
            int d=(ans==INT_MAX)?-1:ans;
            
            res.push_back(d);
        }
        return res;
    }
};