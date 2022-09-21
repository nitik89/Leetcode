class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        unordered_map<int,int>mp;
        int sum=0,idx=0;
        for(auto x:nums){
            mp[idx++]=x;
            if(x%2==0){
                sum+=x;
            }
        }
        vector<int>ans;
        for(auto x:q){
            int v=x[0],idx=x[1];
            if((mp[idx]+v)%2==0){
                if(mp[idx]%2!=0){
                    sum+=(mp[idx]+v);
                }
                else{
                    sum+=v;
                }
            }
            else{
                // cout<<idx<<" ";
                if(mp[idx]%2==0){
                    sum=sum-(mp[idx]);
                }
                
            }
            mp[idx]+=v;
            ans.push_back(sum);
        }
        return ans;
    }
};