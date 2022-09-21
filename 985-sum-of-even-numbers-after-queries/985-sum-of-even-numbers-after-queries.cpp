class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
       
        int sum=0,idx=0;
        for(auto x:nums){
            
            if(x%2==0){
                sum+=x;
            }
        }
        vector<int>ans;
        for(auto x:q){
            int v=x[0],idx=x[1];
            if((nums[idx]+v)%2==0){
                if(nums[idx]%2!=0){
                    sum+=(nums[idx]+v);
                }
                else{
                    sum+=v;
                }
            }
            else{
                // cout<<idx<<" ";
                if(nums[idx]%2==0){
                    sum=sum-(nums[idx]);
                }
                
            }
            nums[idx]+=v;
            ans.push_back(sum);
        }
        return ans;
    }
};