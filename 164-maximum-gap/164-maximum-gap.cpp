class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        if(nums.size()==2){
            return nums[nums.size()-1]-nums[0];
        }
      int mn=*min_element(nums.begin(),nums.end());
      int mx=*max_element(nums.begin(),nums.end());
        
      int n=nums.size();
      vector<pair<int,int>>bucket(n-1,{INT_MAX,INT_MIN}); //mn and mx
      int intervals=(mx-mn)/(n-1)+1;
        // cout<<intervals<<" ";
        
     for(auto x:nums){
         int slot=(x-mn)/intervals;
          // cout<<slot<<" ";
         if(x<bucket[slot].first){
             bucket[slot].first=x;
         }
         if(x>bucket[slot].second){
             bucket[slot].second=x;
         }
        }
    int ans=0;
    int prev=bucket[0].second;
        // cout<<prev<<" "<<bucket[0].first;
    for(int i=1;i<bucket.size();i++){
        // cout<<bucket[i].first<<" "<<bucket[i].second<<"\n";
        if(bucket[i].first!=INT_MAX){
            // cout<<bucket[i].first<<" "<<prev<<"\n";
        ans=max(bucket[i].first-prev,ans);
            prev=bucket[i].second;
        }
        
    }
        return ans;
        
    }
};